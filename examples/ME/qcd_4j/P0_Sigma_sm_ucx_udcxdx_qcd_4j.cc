//==========================================================================
// This file has been automatically generated for C++ Standalone by
// MadGraph 5 v. 2.0.0.beta3, 2013-02-14
// By the MadGraph Development Team
// Please visit us at https://launchpad.net/madgraph5
//==========================================================================

#include "P0_Sigma_sm_ucx_udcxdx_qcd_4j.h"
#include "HelAmps_sm.h"

using namespace MG5_sm; 

//==========================================================================
// Class member functions for calculating the matrix elements for
// Process: u c~ > u d c~ d~ WEIGHTED=4
// Process: u c~ > u s c~ s~ WEIGHTED=4
// Process: u d~ > u c d~ c~ WEIGHTED=4
// Process: u d~ > u s d~ s~ WEIGHTED=4
// Process: u s~ > u c s~ c~ WEIGHTED=4
// Process: u s~ > u d s~ d~ WEIGHTED=4
// Process: c u~ > c d u~ d~ WEIGHTED=4
// Process: c u~ > c s u~ s~ WEIGHTED=4
// Process: c d~ > c u d~ u~ WEIGHTED=4
// Process: c d~ > c s d~ s~ WEIGHTED=4
// Process: c s~ > c u s~ u~ WEIGHTED=4
// Process: c s~ > c d s~ d~ WEIGHTED=4
// Process: d u~ > d c u~ c~ WEIGHTED=4
// Process: d u~ > d s u~ s~ WEIGHTED=4
// Process: d c~ > d u c~ u~ WEIGHTED=4
// Process: d c~ > d s c~ s~ WEIGHTED=4
// Process: d s~ > d u s~ u~ WEIGHTED=4
// Process: d s~ > d c s~ c~ WEIGHTED=4
// Process: s u~ > s c u~ c~ WEIGHTED=4
// Process: s u~ > s d u~ d~ WEIGHTED=4
// Process: s c~ > s u c~ u~ WEIGHTED=4
// Process: s c~ > s d c~ d~ WEIGHTED=4
// Process: s d~ > s u d~ u~ WEIGHTED=4
// Process: s d~ > s c d~ c~ WEIGHTED=4

//--------------------------------------------------------------------------
// Initialize process.

void P0_Sigma_sm_ucx_udcxdx_qcd_4j::initProc(string param_card_name) 
{
  // Instantiate the model class and set parameters that stay fixed during run
  pars = Parameters_sm::getInstance(); 
  SLHAReader slha(param_card_name); 
  pars->setIndependentParameters(slha); 
  pars->setIndependentCouplings(); 
  pars->printIndependentParameters(); 
  pars->printIndependentCouplings(); 
  // Set external particle masses for this matrix element
  mME.push_back(pars->ZERO); 
  mME.push_back(pars->ZERO); 
  mME.push_back(pars->ZERO); 
  mME.push_back(pars->ZERO); 
  mME.push_back(pars->ZERO); 
  mME.push_back(pars->ZERO); 
  jamp2[0] = new double[6]; 
}

//--------------------------------------------------------------------------
// Evaluate |M|^2, part independent of incoming flavour.

void P0_Sigma_sm_ucx_udcxdx_qcd_4j::sigmaKin() 
{
  // Set the parameters which change event by event
  pars->setDependentParameters(); 
  pars->setDependentCouplings(); 
  static bool firsttime = true; 
  if (firsttime)
  {
    pars->printDependentParameters(); 
    pars->printDependentCouplings(); 
    firsttime = false; 
  }

  // Reset color flows
  for(int i = 0; i < 6; i++ )
    jamp2[0][i] = 0.; 

  // Local variables and constants
  const int ncomb = 64; 
  static bool goodhel[ncomb] = {ncomb * false}; 
  static int ntry = 0, sum_hel = 0, ngood = 0; 
  static int igood[ncomb]; 
  static int jhel; 
  std::complex<double> * * wfs; 
  double t[nprocesses]; 
  // Helicities for the process
  static const int helicities[ncomb][nexternal] = {{-1, -1, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, 1}, {-1, -1, -1, -1, 1, -1}, {-1, -1, -1, -1, 1, 1},
      {-1, -1, -1, 1, -1, -1}, {-1, -1, -1, 1, -1, 1}, {-1, -1, -1, 1, 1, -1},
      {-1, -1, -1, 1, 1, 1}, {-1, -1, 1, -1, -1, -1}, {-1, -1, 1, -1, -1, 1},
      {-1, -1, 1, -1, 1, -1}, {-1, -1, 1, -1, 1, 1}, {-1, -1, 1, 1, -1, -1},
      {-1, -1, 1, 1, -1, 1}, {-1, -1, 1, 1, 1, -1}, {-1, -1, 1, 1, 1, 1}, {-1,
      1, -1, -1, -1, -1}, {-1, 1, -1, -1, -1, 1}, {-1, 1, -1, -1, 1, -1}, {-1,
      1, -1, -1, 1, 1}, {-1, 1, -1, 1, -1, -1}, {-1, 1, -1, 1, -1, 1}, {-1, 1,
      -1, 1, 1, -1}, {-1, 1, -1, 1, 1, 1}, {-1, 1, 1, -1, -1, -1}, {-1, 1, 1,
      -1, -1, 1}, {-1, 1, 1, -1, 1, -1}, {-1, 1, 1, -1, 1, 1}, {-1, 1, 1, 1,
      -1, -1}, {-1, 1, 1, 1, -1, 1}, {-1, 1, 1, 1, 1, -1}, {-1, 1, 1, 1, 1, 1},
      {1, -1, -1, -1, -1, -1}, {1, -1, -1, -1, -1, 1}, {1, -1, -1, -1, 1, -1},
      {1, -1, -1, -1, 1, 1}, {1, -1, -1, 1, -1, -1}, {1, -1, -1, 1, -1, 1}, {1,
      -1, -1, 1, 1, -1}, {1, -1, -1, 1, 1, 1}, {1, -1, 1, -1, -1, -1}, {1, -1,
      1, -1, -1, 1}, {1, -1, 1, -1, 1, -1}, {1, -1, 1, -1, 1, 1}, {1, -1, 1, 1,
      -1, -1}, {1, -1, 1, 1, -1, 1}, {1, -1, 1, 1, 1, -1}, {1, -1, 1, 1, 1, 1},
      {1, 1, -1, -1, -1, -1}, {1, 1, -1, -1, -1, 1}, {1, 1, -1, -1, 1, -1}, {1,
      1, -1, -1, 1, 1}, {1, 1, -1, 1, -1, -1}, {1, 1, -1, 1, -1, 1}, {1, 1, -1,
      1, 1, -1}, {1, 1, -1, 1, 1, 1}, {1, 1, 1, -1, -1, -1}, {1, 1, 1, -1, -1,
      1}, {1, 1, 1, -1, 1, -1}, {1, 1, 1, -1, 1, 1}, {1, 1, 1, 1, -1, -1}, {1,
      1, 1, 1, -1, 1}, {1, 1, 1, 1, 1, -1}, {1, 1, 1, 1, 1, 1}};
  // Denominators: spins, colors and identical particles
  const int denominators[nprocesses] = {36, 36}; 

  ntry = ntry + 1; 

  // Reset the matrix elements
  for(int i = 0; i < nprocesses; i++ )
  {
    matrix_element[i] = 0.; 
  }
  // Define permutation
  int perm[nexternal]; 
  for(int i = 0; i < nexternal; i++ )
  {
    perm[i] = i; 
  }

  if (sum_hel == 0 || ntry < 10)
  {
    // Calculate the matrix element for all helicities
    for(int ihel = 0; ihel < ncomb; ihel++ )
    {
      if (goodhel[ihel] || ntry < 2)
      {
        calculate_wavefunctions(perm, helicities[ihel]); 
        t[0] = matrix_ucx_udcxdx(); 
        // Mirror initial state momenta for mirror process
        perm[0] = 1; 
        perm[1] = 0; 
        // Calculate wavefunctions
        calculate_wavefunctions(perm, helicities[ihel]); 
        // Mirror back
        perm[0] = 0; 
        perm[1] = 1; 
        // Calculate matrix elements
        t[1] = matrix_ucx_udcxdx(); 
        double tsum = 0; 
        for(int iproc = 0; iproc < nprocesses; iproc++ )
        {
          matrix_element[iproc] += t[iproc]; 
          tsum += t[iproc]; 
        }
        // Store which helicities give non-zero result
        if (tsum != 0. && !goodhel[ihel])
        {
          goodhel[ihel] = true; 
          ngood++; 
          igood[ngood] = ihel; 
        }
      }
    }
    jhel = 0; 
    sum_hel = min(sum_hel, ngood); 
  }
  else
  {
    // Only use the "good" helicities
    for(int j = 0; j < sum_hel; j++ )
    {
      jhel++; 
      if (jhel >= ngood)
        jhel = 0; 
      double hwgt = double(ngood)/double(sum_hel); 
      int ihel = igood[jhel]; 
      calculate_wavefunctions(perm, helicities[ihel]); 
      t[0] = matrix_ucx_udcxdx(); 
      // Mirror initial state momenta for mirror process
      perm[0] = 1; 
      perm[1] = 0; 
      // Calculate wavefunctions
      calculate_wavefunctions(perm, helicities[ihel]); 
      // Mirror back
      perm[0] = 0; 
      perm[1] = 1; 
      // Calculate matrix elements
      t[1] = matrix_ucx_udcxdx(); 
      for(int iproc = 0; iproc < nprocesses; iproc++ )
      {
        matrix_element[iproc] += t[iproc] * hwgt; 
      }
    }
  }

  for (int i = 0; i < nprocesses; i++ )
    matrix_element[i] /= denominators[i]; 



}

//--------------------------------------------------------------------------
// Evaluate |M|^2, including incoming flavour dependence.

double P0_Sigma_sm_ucx_udcxdx_qcd_4j::sigmaHat() 
{
  // Select between the different processes
  if(id1 == 4 && id2 == -3)
  {
    // Add matrix elements for processes with beams (4, -3)
    return matrix_element[0] * 2; 
  }
  else if(id1 == 2 && id2 == -4)
  {
    // Add matrix elements for processes with beams (2, -4)
    return matrix_element[0] * 2; 
  }
  else if(id1 == -4 && id2 == 2)
  {
    // Add matrix elements for processes with beams (-4, 2)
    return matrix_element[1] * 2; 
  }
  else if(id1 == 3 && id2 == -1)
  {
    // Add matrix elements for processes with beams (3, -1)
    return matrix_element[0] * 2; 
  }
  else if(id1 == 1 && id2 == -2)
  {
    // Add matrix elements for processes with beams (1, -2)
    return matrix_element[0] * 2; 
  }
  else if(id1 == 4 && id2 == -2)
  {
    // Add matrix elements for processes with beams (4, -2)
    return matrix_element[0] * 2; 
  }
  else if(id1 == 2 && id2 == -3)
  {
    // Add matrix elements for processes with beams (2, -3)
    return matrix_element[0] * 2; 
  }
  else if(id1 == -4 && id2 == 3)
  {
    // Add matrix elements for processes with beams (-4, 3)
    return matrix_element[1] * 2; 
  }
  else if(id1 == 4 && id2 == -1)
  {
    // Add matrix elements for processes with beams (4, -1)
    return matrix_element[0] * 2; 
  }
  else if(id1 == 3 && id2 == -4)
  {
    // Add matrix elements for processes with beams (3, -4)
    return matrix_element[0] * 2; 
  }
  else if(id1 == 1 && id2 == -3)
  {
    // Add matrix elements for processes with beams (1, -3)
    return matrix_element[0] * 2; 
  }
  else if(id1 == 2 && id2 == -1)
  {
    // Add matrix elements for processes with beams (2, -1)
    return matrix_element[0] * 2; 
  }
  else if(id1 == -1 && id2 == 2)
  {
    // Add matrix elements for processes with beams (-1, 2)
    return matrix_element[1] * 2; 
  }
  else if(id1 == -2 && id2 == 1)
  {
    // Add matrix elements for processes with beams (-2, 1)
    return matrix_element[1] * 2; 
  }
  else if(id1 == -3 && id2 == 1)
  {
    // Add matrix elements for processes with beams (-3, 1)
    return matrix_element[1] * 2; 
  }
  else if(id1 == 1 && id2 == -4)
  {
    // Add matrix elements for processes with beams (1, -4)
    return matrix_element[0] * 2; 
  }
  else if(id1 == -2 && id2 == 4)
  {
    // Add matrix elements for processes with beams (-2, 4)
    return matrix_element[1] * 2; 
  }
  else if(id1 == -2 && id2 == 3)
  {
    // Add matrix elements for processes with beams (-2, 3)
    return matrix_element[1] * 2; 
  }
  else if(id1 == -3 && id2 == 2)
  {
    // Add matrix elements for processes with beams (-3, 2)
    return matrix_element[1] * 2; 
  }
  else if(id1 == 3 && id2 == -2)
  {
    // Add matrix elements for processes with beams (3, -2)
    return matrix_element[0] * 2; 
  }
  else if(id1 == -1 && id2 == 3)
  {
    // Add matrix elements for processes with beams (-1, 3)
    return matrix_element[1] * 2; 
  }
  else if(id1 == -4 && id2 == 1)
  {
    // Add matrix elements for processes with beams (-4, 1)
    return matrix_element[1] * 2; 
  }
  else if(id1 == -1 && id2 == 4)
  {
    // Add matrix elements for processes with beams (-1, 4)
    return matrix_element[1] * 2; 
  }
  else if(id1 == -3 && id2 == 4)
  {
    // Add matrix elements for processes with beams (-3, 4)
    return matrix_element[1] * 2; 
  }
  else
  {
    // Return 0 if not correct initial state assignment
    return 0.; 
  }
}

//==========================================================================
// Private class member functions

//--------------------------------------------------------------------------
// Evaluate |M|^2 for each subprocess

void P0_Sigma_sm_ucx_udcxdx_qcd_4j::calculate_wavefunctions(const int perm[], const int hel[])
{
  // Calculate wavefunctions for all processes
  int i, j; 

  // Calculate all wavefunctions
  ixxxxx(p[perm[0]], mME[0], hel[0], +1, w[0]); 
  oxxxxx(p[perm[1]], mME[1], hel[1], -1, w[1]); 
  oxxxxx(p[perm[2]], mME[2], hel[2], +1, w[2]); 
  oxxxxx(p[perm[3]], mME[3], hel[3], +1, w[3]); 
  ixxxxx(p[perm[4]], mME[4], hel[4], -1, w[4]); 
  ixxxxx(p[perm[5]], mME[5], hel[5], -1, w[5]); 
  FFV1_3(w[0], w[2], pars->GC_11, pars->ZERO, pars->ZERO, w[6]); 
  FFV1_3(w[4], w[1], pars->GC_11, pars->ZERO, pars->ZERO, w[7]); 
  FFV1_1(w[3], w[6], pars->GC_11, pars->ZERO, pars->ZERO, w[8]); 
  FFV1_2(w[5], w[6], pars->GC_11, pars->ZERO, pars->ZERO, w[9]); 
  FFV1_3(w[5], w[3], pars->GC_11, pars->ZERO, pars->ZERO, w[10]); 
  FFV1_2(w[4], w[6], pars->GC_11, pars->ZERO, pars->ZERO, w[11]); 
  FFV1_1(w[1], w[6], pars->GC_11, pars->ZERO, pars->ZERO, w[12]); 
  FFV1_2(w[0], w[7], pars->GC_11, pars->ZERO, pars->ZERO, w[13]); 
  FFV1_2(w[0], w[10], pars->GC_11, pars->ZERO, pars->ZERO, w[14]); 

  // Calculate all amplitudes
  // Amplitude(s) for diagram number 0
  FFV1_0(w[5], w[8], w[7], pars->GC_11, amp[0]); 
  FFV1_0(w[9], w[3], w[7], pars->GC_11, amp[1]); 
  VVV1_0(w[6], w[7], w[10], pars->GC_10, amp[2]); 
  FFV1_0(w[11], w[1], w[10], pars->GC_11, amp[3]); 
  FFV1_0(w[4], w[12], w[10], pars->GC_11, amp[4]); 
  FFV1_0(w[13], w[2], w[10], pars->GC_11, amp[5]); 
  FFV1_0(w[14], w[2], w[7], pars->GC_11, amp[6]); 

}
double P0_Sigma_sm_ucx_udcxdx_qcd_4j::matrix_ucx_udcxdx() 
{
  int i, j; 
  // Local variables
  const int ngraphs = 7; 
  const int ncolor = 6; 
  std::complex<double> ztemp; 
  std::complex<double> jamp[ncolor]; 
  // The color matrix;
  static const double denom[ncolor] = {1, 1, 1, 1, 1, 1}; 
  static const double cf[ncolor][ncolor] = {{27, 9, 9, 3, 3, 9}, {9, 27, 3, 9,
      9, 3}, {9, 3, 27, 9, 9, 3}, {3, 9, 9, 27, 3, 9}, {3, 9, 9, 3, 27, 9}, {9,
      3, 3, 9, 9, 27}};

  // Calculate color flows
  jamp[0] = +1./4. * (-1./3. * amp[3] - 1./3. * amp[4] - 1./3. * amp[5] - 1./3.
      * amp[6]);
  jamp[1] = +1./4. * (+amp[1] + std::complex<double> (0, 1) * amp[2] + amp[4] +
      amp[5]);
  jamp[2] = +1./4. * (+1./9. * amp[0] + 1./9. * amp[1] + 1./9. * amp[3] + 1./9.
      * amp[4] + 1./9. * amp[5] + 1./9. * amp[6]);
  jamp[3] = +1./4. * (-1./3. * amp[0] - 1./3. * amp[1] - 1./3. * amp[5] - 1./3.
      * amp[6]);
  jamp[4] = +1./4. * (-1./3. * amp[0] - 1./3. * amp[1] - 1./3. * amp[3] - 1./3.
      * amp[4]);
  jamp[5] = +1./4. * (+amp[0] - std::complex<double> (0, 1) * amp[2] + amp[3] +
      amp[6]);

  // Sum and square the color flows to get the matrix element
  double matrix = 0; 
  for(i = 0; i < ncolor; i++ )
  {
    ztemp = 0.; 
    for(j = 0; j < ncolor; j++ )
      ztemp = ztemp + cf[i][j] * jamp[j]; 
    matrix = matrix + real(ztemp * conj(jamp[i]))/denom[i]; 
  }

  // Store the leading color flows for choice of color
  for(i = 0; i < ncolor; i++ )
    jamp2[0][i] += real(jamp[i] * conj(jamp[i])); 

  return matrix; 
}



