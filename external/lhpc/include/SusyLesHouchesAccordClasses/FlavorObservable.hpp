/*
 * FlavorObservable.hpp
 *
 *  Created on: Apr 1, 2012 (really!)
 *      Author: Ben O'Leary (benjamin.oleary@gmail.com)
 *      Copyright 2012 Ben O'Leary
 *
 *      This file is part of LesHouchesParserClasses, released under the
 *      GNU General Public License. Please see the accompanying
 *      README.LHPC_CPP.txt file for a full list of files, brief documentation
 *      on how to use these classes, and further details on the license.
 */

#ifndef FLAVOROBSERVABLE_HPP_
#define FLAVOROBSERVABLE_HPP_

#include <string>
#include "BOLlib/include/BOLlib.hpp"

namespace LHPC
{
  // this is a class to hold the information about the mass of a particle in
  // the FLHA format.
  class FlavorObservable
  {
  public:
    static int const spacesBetweenCodes;
    static int const minimumDigitsForCodes;

    FlavorObservable();
    FlavorObservable( FlavorObservable const& copySource );
    ~FlavorObservable();

    double
    getValue() const;
    double
    getScale() const;
    int
    getNumberOfDaughterParticles() const;
    std::list< int >&
    getDaughterParticleList();
    std::list< int > const&
    getDaughterParticleList() const;
    void
    setValues( double const valueDouble,
               double const evaluationScale,
               std::list< int > const& daughterParticleCodes );
    void
    setFromString( std::string const& valuesString );
    std::string
    getAsString() const;


  protected:
    double valueDouble;
    double evaluationScale;
    std::list< int > daughterParticleCodes;
  };





  inline double
  FlavorObservable::getValue() const
  {
    return valueDouble;
  }

  inline double
  FlavorObservable::getScale() const
  {
    return evaluationScale;
  }

  inline int
  FlavorObservable::getNumberOfDaughterParticles() const
  {
    return (int)(daughterParticleCodes.size());
  }

  inline std::list< int >&
  FlavorObservable::getDaughterParticleList()
  {
    return daughterParticleCodes;
  }

  inline std::list< int > const&
  FlavorObservable::getDaughterParticleList() const
  {
    return daughterParticleCodes;
  }

  inline void
  FlavorObservable::setValues( double const valueDouble,
                               double const evaluationScale,
                               std::list< int > const& daughterParticleCodes )
  {
    this->valueDouble = valueDouble;
    this->evaluationScale = evaluationScale;
    this->daughterParticleCodes = daughterParticleCodes;
  }

}

#endif /* FLAVOROBSERVABLE_HPP_ */
