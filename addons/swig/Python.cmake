# SETUP PYTHON

# get default python inerpreter
FIND_PROGRAM( PYTHON_EXECUTABLE python REQUIRED
	PATHS [HKEY_LOCAL_MACHINE\\SOFTWARE\\Python\\PythonCore\\2.7\\InstallPath] [HKEY_LOCAL_MACHINE\\SOFTWARE\\Python\\PythonCore\\2.6\\InstallPath] [HKEY_LOCAL_MACHINE\\SOFTWARE\\Python\\PythonCore\\2.5\\InstallPath]
) 

SET(PYTHONINTERP_FOUND TRUE)

# find python include path
execute_process(
	COMMAND ${PYTHON_EXECUTABLE} -c "import sys; from distutils import sysconfig; sys.stdout.write(sysconfig.get_python_inc())"
	OUTPUT_VARIABLE PYTHON_INCLUDE_PATH
	OUTPUT_STRIP_TRAILING_WHITESPACE
)

FIND_FILE(PYTHON_H_FOUND Python.h ${PYTHON_INCLUDE_PATH})
IF(NOT PYTHON_H_FOUND)
	MESSAGE(SEND_ERROR "Python.h not found")
ENDIF()

# use python framework mechanism on apple for the libs
IF(APPLE)
	INCLUDE(CMakeFindFrameworks)
	# Search for the python framework on Apple.
	MESSAGE(INFO "Looking for python framework as on apple system" )
	CMAKE_FIND_FRAMEWORKS(Python)

	SET (PYTHON_LIBRARIES "-framework Python" CACHE FILEPATH "Python Framework" FORCE)
ENDIF(APPLE)

IF(MSVC)
	execute_process(
		COMMAND ${PYTHON_EXECUTABLE} -c "import sys; from distutils import sysconfig; import os; prefix= sysconfig.get_config_var('prefix'); ver = sysconfig.get_python_version().replace('.', ''); lib = os.path.join(prefix,'libs\\python'+ver+'.lib'); sys.stdout.write(lib)"
		OUTPUT_VARIABLE PYTHON_LIBRARIES
		OUTPUT_STRIP_TRAILING_WHITESPACE
	)
ENDIF(MSVC)

IF (MINGW)
	execute_process(
		COMMAND ${PYTHON_EXECUTABLE} -c "import sys; from distutils import sysconfig; import os; prefix= sysconfig.get_config_var('prefix'); ver = sysconfig.get_python_version().replace('.', ''); lib = os.path.join(prefix,'libs\\libpython'+ver+'.a'); sys.stdout.write(lib)"
		OUTPUT_VARIABLE PYTHON_LIBRARIES
		OUTPUT_STRIP_TRAILING_WHITESPACE
	)
ENDIF(MINGW)

IF(NOT APPLE AND NOT MSVC AND NOT MINGW)
	execute_process(
		COMMAND ${PYTHON_EXECUTABLE} -c "import sys; from distutils import sysconfig; import os; libname = sysconfig.get_config_var('LDLIBRARY'); libdir= sysconfig.get_config_var('LIBDIR'); lib = os.path.join(libdir,libname); sys.stdout.write(lib)"
		OUTPUT_VARIABLE PYTHON_LIBRARIES
		OUTPUT_STRIP_TRAILING_WHITESPACE
	)
ENDIF(NOT APPLE AND NOT MSVC AND NOT MINGW)

#find the site package destinaton 
execute_process(
	COMMAND ${PYTHON_EXECUTABLE} -c "import sys; from distutils import sysconfig; sys.stdout.write(sysconfig.get_python_lib(1,0,prefix='${CMAKE_INSTALL_PREFIX}'))"
	OUTPUT_VARIABLE PYTHON_SITE_PACKAGES
	OUTPUT_STRIP_TRAILING_WHITESPACE
)

execute_process(
	COMMAND ${PYTHON_EXECUTABLE} -c "import sys; sys.stdout.write(str(sys.version_info[0]))"
	OUTPUT_VARIABLE PYTHON_MAJOR_VERSION
	OUTPUT_STRIP_TRAILING_WHITESPACE
)

execute_process(
	COMMAND ${PYTHON_EXECUTABLE} -c "import sys; sys.stdout.write(str(sys.version_info[1]))"
	OUTPUT_VARIABLE PYTHON_MINOR_VERSION
	OUTPUT_STRIP_TRAILING_WHITESPACE
)

SET(PYTHON_VERSION "${PYTHON_MAJOR_VERSION}${PYTHON_MINOR_VERSION}")
SET(PYTHON_DOT_VERSION "${PYTHON_MAJOR_VERSION}.${PYTHON_MINOR_VERSION}")

MESSAGE(STATUS "Found Python executeable: " ${PYTHON_EXECUTABLE})
MESSAGE(STATUS "Found Python include path: " ${PYTHON_INCLUDE_PATH})
MESSAGE(STATUS "Found Python library: " ${PYTHON_LIBRARIES})
MESSAGE(STATUS "Using Python site-package directory: " ${PYTHON_SITE_PACKAGES})
MESSAGE(STATUS "Using Python Version: " ${PYTHON_DOT_VERSION} "/" ${PYTHON_VERSION})
