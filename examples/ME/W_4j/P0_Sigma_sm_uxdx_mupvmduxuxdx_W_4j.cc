//==========================================================================
// This file has been automatically generated for C++ Standalone by
// MadGraph 5 v. 2.0.0.beta3, 2013-02-14
// By the MadGraph Development Team
// Please visit us at https://launchpad.net/madgraph5
//==========================================================================

#include "P0_Sigma_sm_uxdx_mupvmduxuxdx_W_4j.h"
#include "HelAmps_sm.h"

using namespace MG5_sm; 

//==========================================================================
// Class member functions for calculating the matrix elements for
// Process: u~ d~ > w+ d u~ u~ d~ WEIGHTED=6
// *   Decay: w+ > mu+ vm WEIGHTED=2
// Process: c~ s~ > w+ s c~ c~ s~ WEIGHTED=6
// *   Decay: w+ > mu+ vm WEIGHTED=2

//--------------------------------------------------------------------------
// Initialize process.

void P0_Sigma_sm_uxdx_mupvmduxuxdx_W_4j::initProc(string param_card_name) 
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
  mME.push_back(pars->ZERO); 
  mME.push_back(pars->ZERO); 
  jamp2[0] = new double[6]; 
}

//--------------------------------------------------------------------------
// Evaluate |M|^2, part independent of incoming flavour.

void P0_Sigma_sm_uxdx_mupvmduxuxdx_W_4j::sigmaKin() 
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
  const int ncomb = 256; 
  static bool goodhel[ncomb] = {ncomb * false}; 
  static int ntry = 0, sum_hel = 0, ngood = 0; 
  static int igood[ncomb]; 
  static int jhel; 
  std::complex<double> * * wfs; 
  double t[nprocesses]; 
  // Helicities for the process
  static const int helicities[ncomb][nexternal] = {{-1, -1, -1, -1, -1, -1, -1,
      -1}, {-1, -1, -1, -1, -1, -1, -1, 1}, {-1, -1, -1, -1, -1, -1, 1, -1},
      {-1, -1, -1, -1, -1, -1, 1, 1}, {-1, -1, -1, -1, -1, 1, -1, -1}, {-1, -1,
      -1, -1, -1, 1, -1, 1}, {-1, -1, -1, -1, -1, 1, 1, -1}, {-1, -1, -1, -1,
      -1, 1, 1, 1}, {-1, -1, -1, -1, 1, -1, -1, -1}, {-1, -1, -1, -1, 1, -1,
      -1, 1}, {-1, -1, -1, -1, 1, -1, 1, -1}, {-1, -1, -1, -1, 1, -1, 1, 1},
      {-1, -1, -1, -1, 1, 1, -1, -1}, {-1, -1, -1, -1, 1, 1, -1, 1}, {-1, -1,
      -1, -1, 1, 1, 1, -1}, {-1, -1, -1, -1, 1, 1, 1, 1}, {-1, -1, -1, 1, -1,
      -1, -1, -1}, {-1, -1, -1, 1, -1, -1, -1, 1}, {-1, -1, -1, 1, -1, -1, 1,
      -1}, {-1, -1, -1, 1, -1, -1, 1, 1}, {-1, -1, -1, 1, -1, 1, -1, -1}, {-1,
      -1, -1, 1, -1, 1, -1, 1}, {-1, -1, -1, 1, -1, 1, 1, -1}, {-1, -1, -1, 1,
      -1, 1, 1, 1}, {-1, -1, -1, 1, 1, -1, -1, -1}, {-1, -1, -1, 1, 1, -1, -1,
      1}, {-1, -1, -1, 1, 1, -1, 1, -1}, {-1, -1, -1, 1, 1, -1, 1, 1}, {-1, -1,
      -1, 1, 1, 1, -1, -1}, {-1, -1, -1, 1, 1, 1, -1, 1}, {-1, -1, -1, 1, 1, 1,
      1, -1}, {-1, -1, -1, 1, 1, 1, 1, 1}, {-1, -1, 1, -1, -1, -1, -1, -1},
      {-1, -1, 1, -1, -1, -1, -1, 1}, {-1, -1, 1, -1, -1, -1, 1, -1}, {-1, -1,
      1, -1, -1, -1, 1, 1}, {-1, -1, 1, -1, -1, 1, -1, -1}, {-1, -1, 1, -1, -1,
      1, -1, 1}, {-1, -1, 1, -1, -1, 1, 1, -1}, {-1, -1, 1, -1, -1, 1, 1, 1},
      {-1, -1, 1, -1, 1, -1, -1, -1}, {-1, -1, 1, -1, 1, -1, -1, 1}, {-1, -1,
      1, -1, 1, -1, 1, -1}, {-1, -1, 1, -1, 1, -1, 1, 1}, {-1, -1, 1, -1, 1, 1,
      -1, -1}, {-1, -1, 1, -1, 1, 1, -1, 1}, {-1, -1, 1, -1, 1, 1, 1, -1}, {-1,
      -1, 1, -1, 1, 1, 1, 1}, {-1, -1, 1, 1, -1, -1, -1, -1}, {-1, -1, 1, 1,
      -1, -1, -1, 1}, {-1, -1, 1, 1, -1, -1, 1, -1}, {-1, -1, 1, 1, -1, -1, 1,
      1}, {-1, -1, 1, 1, -1, 1, -1, -1}, {-1, -1, 1, 1, -1, 1, -1, 1}, {-1, -1,
      1, 1, -1, 1, 1, -1}, {-1, -1, 1, 1, -1, 1, 1, 1}, {-1, -1, 1, 1, 1, -1,
      -1, -1}, {-1, -1, 1, 1, 1, -1, -1, 1}, {-1, -1, 1, 1, 1, -1, 1, -1}, {-1,
      -1, 1, 1, 1, -1, 1, 1}, {-1, -1, 1, 1, 1, 1, -1, -1}, {-1, -1, 1, 1, 1,
      1, -1, 1}, {-1, -1, 1, 1, 1, 1, 1, -1}, {-1, -1, 1, 1, 1, 1, 1, 1}, {-1,
      1, -1, -1, -1, -1, -1, -1}, {-1, 1, -1, -1, -1, -1, -1, 1}, {-1, 1, -1,
      -1, -1, -1, 1, -1}, {-1, 1, -1, -1, -1, -1, 1, 1}, {-1, 1, -1, -1, -1, 1,
      -1, -1}, {-1, 1, -1, -1, -1, 1, -1, 1}, {-1, 1, -1, -1, -1, 1, 1, -1},
      {-1, 1, -1, -1, -1, 1, 1, 1}, {-1, 1, -1, -1, 1, -1, -1, -1}, {-1, 1, -1,
      -1, 1, -1, -1, 1}, {-1, 1, -1, -1, 1, -1, 1, -1}, {-1, 1, -1, -1, 1, -1,
      1, 1}, {-1, 1, -1, -1, 1, 1, -1, -1}, {-1, 1, -1, -1, 1, 1, -1, 1}, {-1,
      1, -1, -1, 1, 1, 1, -1}, {-1, 1, -1, -1, 1, 1, 1, 1}, {-1, 1, -1, 1, -1,
      -1, -1, -1}, {-1, 1, -1, 1, -1, -1, -1, 1}, {-1, 1, -1, 1, -1, -1, 1,
      -1}, {-1, 1, -1, 1, -1, -1, 1, 1}, {-1, 1, -1, 1, -1, 1, -1, -1}, {-1, 1,
      -1, 1, -1, 1, -1, 1}, {-1, 1, -1, 1, -1, 1, 1, -1}, {-1, 1, -1, 1, -1, 1,
      1, 1}, {-1, 1, -1, 1, 1, -1, -1, -1}, {-1, 1, -1, 1, 1, -1, -1, 1}, {-1,
      1, -1, 1, 1, -1, 1, -1}, {-1, 1, -1, 1, 1, -1, 1, 1}, {-1, 1, -1, 1, 1,
      1, -1, -1}, {-1, 1, -1, 1, 1, 1, -1, 1}, {-1, 1, -1, 1, 1, 1, 1, -1},
      {-1, 1, -1, 1, 1, 1, 1, 1}, {-1, 1, 1, -1, -1, -1, -1, -1}, {-1, 1, 1,
      -1, -1, -1, -1, 1}, {-1, 1, 1, -1, -1, -1, 1, -1}, {-1, 1, 1, -1, -1, -1,
      1, 1}, {-1, 1, 1, -1, -1, 1, -1, -1}, {-1, 1, 1, -1, -1, 1, -1, 1}, {-1,
      1, 1, -1, -1, 1, 1, -1}, {-1, 1, 1, -1, -1, 1, 1, 1}, {-1, 1, 1, -1, 1,
      -1, -1, -1}, {-1, 1, 1, -1, 1, -1, -1, 1}, {-1, 1, 1, -1, 1, -1, 1, -1},
      {-1, 1, 1, -1, 1, -1, 1, 1}, {-1, 1, 1, -1, 1, 1, -1, -1}, {-1, 1, 1, -1,
      1, 1, -1, 1}, {-1, 1, 1, -1, 1, 1, 1, -1}, {-1, 1, 1, -1, 1, 1, 1, 1},
      {-1, 1, 1, 1, -1, -1, -1, -1}, {-1, 1, 1, 1, -1, -1, -1, 1}, {-1, 1, 1,
      1, -1, -1, 1, -1}, {-1, 1, 1, 1, -1, -1, 1, 1}, {-1, 1, 1, 1, -1, 1, -1,
      -1}, {-1, 1, 1, 1, -1, 1, -1, 1}, {-1, 1, 1, 1, -1, 1, 1, -1}, {-1, 1, 1,
      1, -1, 1, 1, 1}, {-1, 1, 1, 1, 1, -1, -1, -1}, {-1, 1, 1, 1, 1, -1, -1,
      1}, {-1, 1, 1, 1, 1, -1, 1, -1}, {-1, 1, 1, 1, 1, -1, 1, 1}, {-1, 1, 1,
      1, 1, 1, -1, -1}, {-1, 1, 1, 1, 1, 1, -1, 1}, {-1, 1, 1, 1, 1, 1, 1, -1},
      {-1, 1, 1, 1, 1, 1, 1, 1}, {1, -1, -1, -1, -1, -1, -1, -1}, {1, -1, -1,
      -1, -1, -1, -1, 1}, {1, -1, -1, -1, -1, -1, 1, -1}, {1, -1, -1, -1, -1,
      -1, 1, 1}, {1, -1, -1, -1, -1, 1, -1, -1}, {1, -1, -1, -1, -1, 1, -1, 1},
      {1, -1, -1, -1, -1, 1, 1, -1}, {1, -1, -1, -1, -1, 1, 1, 1}, {1, -1, -1,
      -1, 1, -1, -1, -1}, {1, -1, -1, -1, 1, -1, -1, 1}, {1, -1, -1, -1, 1, -1,
      1, -1}, {1, -1, -1, -1, 1, -1, 1, 1}, {1, -1, -1, -1, 1, 1, -1, -1}, {1,
      -1, -1, -1, 1, 1, -1, 1}, {1, -1, -1, -1, 1, 1, 1, -1}, {1, -1, -1, -1,
      1, 1, 1, 1}, {1, -1, -1, 1, -1, -1, -1, -1}, {1, -1, -1, 1, -1, -1, -1,
      1}, {1, -1, -1, 1, -1, -1, 1, -1}, {1, -1, -1, 1, -1, -1, 1, 1}, {1, -1,
      -1, 1, -1, 1, -1, -1}, {1, -1, -1, 1, -1, 1, -1, 1}, {1, -1, -1, 1, -1,
      1, 1, -1}, {1, -1, -1, 1, -1, 1, 1, 1}, {1, -1, -1, 1, 1, -1, -1, -1},
      {1, -1, -1, 1, 1, -1, -1, 1}, {1, -1, -1, 1, 1, -1, 1, -1}, {1, -1, -1,
      1, 1, -1, 1, 1}, {1, -1, -1, 1, 1, 1, -1, -1}, {1, -1, -1, 1, 1, 1, -1,
      1}, {1, -1, -1, 1, 1, 1, 1, -1}, {1, -1, -1, 1, 1, 1, 1, 1}, {1, -1, 1,
      -1, -1, -1, -1, -1}, {1, -1, 1, -1, -1, -1, -1, 1}, {1, -1, 1, -1, -1,
      -1, 1, -1}, {1, -1, 1, -1, -1, -1, 1, 1}, {1, -1, 1, -1, -1, 1, -1, -1},
      {1, -1, 1, -1, -1, 1, -1, 1}, {1, -1, 1, -1, -1, 1, 1, -1}, {1, -1, 1,
      -1, -1, 1, 1, 1}, {1, -1, 1, -1, 1, -1, -1, -1}, {1, -1, 1, -1, 1, -1,
      -1, 1}, {1, -1, 1, -1, 1, -1, 1, -1}, {1, -1, 1, -1, 1, -1, 1, 1}, {1,
      -1, 1, -1, 1, 1, -1, -1}, {1, -1, 1, -1, 1, 1, -1, 1}, {1, -1, 1, -1, 1,
      1, 1, -1}, {1, -1, 1, -1, 1, 1, 1, 1}, {1, -1, 1, 1, -1, -1, -1, -1}, {1,
      -1, 1, 1, -1, -1, -1, 1}, {1, -1, 1, 1, -1, -1, 1, -1}, {1, -1, 1, 1, -1,
      -1, 1, 1}, {1, -1, 1, 1, -1, 1, -1, -1}, {1, -1, 1, 1, -1, 1, -1, 1}, {1,
      -1, 1, 1, -1, 1, 1, -1}, {1, -1, 1, 1, -1, 1, 1, 1}, {1, -1, 1, 1, 1, -1,
      -1, -1}, {1, -1, 1, 1, 1, -1, -1, 1}, {1, -1, 1, 1, 1, -1, 1, -1}, {1,
      -1, 1, 1, 1, -1, 1, 1}, {1, -1, 1, 1, 1, 1, -1, -1}, {1, -1, 1, 1, 1, 1,
      -1, 1}, {1, -1, 1, 1, 1, 1, 1, -1}, {1, -1, 1, 1, 1, 1, 1, 1}, {1, 1, -1,
      -1, -1, -1, -1, -1}, {1, 1, -1, -1, -1, -1, -1, 1}, {1, 1, -1, -1, -1,
      -1, 1, -1}, {1, 1, -1, -1, -1, -1, 1, 1}, {1, 1, -1, -1, -1, 1, -1, -1},
      {1, 1, -1, -1, -1, 1, -1, 1}, {1, 1, -1, -1, -1, 1, 1, -1}, {1, 1, -1,
      -1, -1, 1, 1, 1}, {1, 1, -1, -1, 1, -1, -1, -1}, {1, 1, -1, -1, 1, -1,
      -1, 1}, {1, 1, -1, -1, 1, -1, 1, -1}, {1, 1, -1, -1, 1, -1, 1, 1}, {1, 1,
      -1, -1, 1, 1, -1, -1}, {1, 1, -1, -1, 1, 1, -1, 1}, {1, 1, -1, -1, 1, 1,
      1, -1}, {1, 1, -1, -1, 1, 1, 1, 1}, {1, 1, -1, 1, -1, -1, -1, -1}, {1, 1,
      -1, 1, -1, -1, -1, 1}, {1, 1, -1, 1, -1, -1, 1, -1}, {1, 1, -1, 1, -1,
      -1, 1, 1}, {1, 1, -1, 1, -1, 1, -1, -1}, {1, 1, -1, 1, -1, 1, -1, 1}, {1,
      1, -1, 1, -1, 1, 1, -1}, {1, 1, -1, 1, -1, 1, 1, 1}, {1, 1, -1, 1, 1, -1,
      -1, -1}, {1, 1, -1, 1, 1, -1, -1, 1}, {1, 1, -1, 1, 1, -1, 1, -1}, {1, 1,
      -1, 1, 1, -1, 1, 1}, {1, 1, -1, 1, 1, 1, -1, -1}, {1, 1, -1, 1, 1, 1, -1,
      1}, {1, 1, -1, 1, 1, 1, 1, -1}, {1, 1, -1, 1, 1, 1, 1, 1}, {1, 1, 1, -1,
      -1, -1, -1, -1}, {1, 1, 1, -1, -1, -1, -1, 1}, {1, 1, 1, -1, -1, -1, 1,
      -1}, {1, 1, 1, -1, -1, -1, 1, 1}, {1, 1, 1, -1, -1, 1, -1, -1}, {1, 1, 1,
      -1, -1, 1, -1, 1}, {1, 1, 1, -1, -1, 1, 1, -1}, {1, 1, 1, -1, -1, 1, 1,
      1}, {1, 1, 1, -1, 1, -1, -1, -1}, {1, 1, 1, -1, 1, -1, -1, 1}, {1, 1, 1,
      -1, 1, -1, 1, -1}, {1, 1, 1, -1, 1, -1, 1, 1}, {1, 1, 1, -1, 1, 1, -1,
      -1}, {1, 1, 1, -1, 1, 1, -1, 1}, {1, 1, 1, -1, 1, 1, 1, -1}, {1, 1, 1,
      -1, 1, 1, 1, 1}, {1, 1, 1, 1, -1, -1, -1, -1}, {1, 1, 1, 1, -1, -1, -1,
      1}, {1, 1, 1, 1, -1, -1, 1, -1}, {1, 1, 1, 1, -1, -1, 1, 1}, {1, 1, 1, 1,
      -1, 1, -1, -1}, {1, 1, 1, 1, -1, 1, -1, 1}, {1, 1, 1, 1, -1, 1, 1, -1},
      {1, 1, 1, 1, -1, 1, 1, 1}, {1, 1, 1, 1, 1, -1, -1, -1}, {1, 1, 1, 1, 1,
      -1, -1, 1}, {1, 1, 1, 1, 1, -1, 1, -1}, {1, 1, 1, 1, 1, -1, 1, 1}, {1, 1,
      1, 1, 1, 1, -1, -1}, {1, 1, 1, 1, 1, 1, -1, 1}, {1, 1, 1, 1, 1, 1, 1,
      -1}, {1, 1, 1, 1, 1, 1, 1, 1}};
  // Denominators: spins, colors and identical particles
  const int denominators[nprocesses] = {72, 72}; 

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
        t[0] = matrix_uxdx_wpduxuxdx_wp_mupvm(); 
        // Mirror initial state momenta for mirror process
        perm[0] = 1; 
        perm[1] = 0; 
        // Calculate wavefunctions
        calculate_wavefunctions(perm, helicities[ihel]); 
        // Mirror back
        perm[0] = 0; 
        perm[1] = 1; 
        // Calculate matrix elements
        t[1] = matrix_uxdx_wpduxuxdx_wp_mupvm(); 
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
      t[0] = matrix_uxdx_wpduxuxdx_wp_mupvm(); 
      // Mirror initial state momenta for mirror process
      perm[0] = 1; 
      perm[1] = 0; 
      // Calculate wavefunctions
      calculate_wavefunctions(perm, helicities[ihel]); 
      // Mirror back
      perm[0] = 0; 
      perm[1] = 1; 
      // Calculate matrix elements
      t[1] = matrix_uxdx_wpduxuxdx_wp_mupvm(); 
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

double P0_Sigma_sm_uxdx_mupvmduxuxdx_W_4j::sigmaHat() 
{
  // Select between the different processes
  if(id1 == -4 && id2 == -3)
  {
    // Add matrix elements for processes with beams (-4, -3)
    return matrix_element[0]; 
  }
  else if(id1 == -3 && id2 == -4)
  {
    // Add matrix elements for processes with beams (-3, -4)
    return matrix_element[1]; 
  }
  else if(id1 == -1 && id2 == -2)
  {
    // Add matrix elements for processes with beams (-1, -2)
    return matrix_element[1]; 
  }
  else if(id1 == -2 && id2 == -1)
  {
    // Add matrix elements for processes with beams (-2, -1)
    return matrix_element[0]; 
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

void P0_Sigma_sm_uxdx_mupvmduxuxdx_W_4j::calculate_wavefunctions(const int perm[], const int hel[])
{
  // Calculate wavefunctions for all processes
  int i, j; 

  // Calculate all wavefunctions
  oxxxxx(p[perm[0]], mME[0], hel[0], -1, w[0]); 
  oxxxxx(p[perm[1]], mME[1], hel[1], -1, w[1]); 
  ixxxxx(p[perm[2]], mME[2], hel[2], -1, w[2]); 
  oxxxxx(p[perm[3]], mME[3], hel[3], +1, w[3]); 
  FFV2_3(w[2], w[3], pars->GC_100, pars->MW, pars->WW, w[4]); 
  oxxxxx(p[perm[4]], mME[4], hel[4], +1, w[5]); 
  ixxxxx(p[perm[5]], mME[5], hel[5], -1, w[6]); 
  ixxxxx(p[perm[6]], mME[6], hel[6], -1, w[7]); 
  ixxxxx(p[perm[7]], mME[7], hel[7], -1, w[8]); 
  FFV2_2(w[6], w[4], pars->GC_100, pars->ZERO, pars->ZERO, w[9]); 
  FFV1_3(w[7], w[0], pars->GC_11, pars->ZERO, pars->ZERO, w[10]); 
  FFV1_3(w[9], w[1], pars->GC_11, pars->ZERO, pars->ZERO, w[11]); 
  FFV1_1(w[5], w[10], pars->GC_11, pars->ZERO, pars->ZERO, w[12]); 
  FFV1_2(w[8], w[10], pars->GC_11, pars->ZERO, pars->ZERO, w[13]); 
  FFV1_3(w[9], w[5], pars->GC_11, pars->ZERO, pars->ZERO, w[14]); 
  FFV1_1(w[1], w[10], pars->GC_11, pars->ZERO, pars->ZERO, w[15]); 
  FFV1_3(w[8], w[1], pars->GC_11, pars->ZERO, pars->ZERO, w[16]); 
  FFV1_2(w[9], w[10], pars->GC_11, pars->ZERO, pars->ZERO, w[17]); 
  FFV1_2(w[9], w[16], pars->GC_11, pars->ZERO, pars->ZERO, w[18]); 
  FFV1_3(w[8], w[5], pars->GC_11, pars->ZERO, pars->ZERO, w[19]); 
  FFV1_2(w[9], w[19], pars->GC_11, pars->ZERO, pars->ZERO, w[20]); 
  FFV1_2(w[7], w[16], pars->GC_11, pars->ZERO, pars->ZERO, w[21]); 
  FFV1_1(w[0], w[16], pars->GC_11, pars->ZERO, pars->ZERO, w[22]); 
  FFV1_2(w[7], w[19], pars->GC_11, pars->ZERO, pars->ZERO, w[23]); 
  FFV1_1(w[0], w[19], pars->GC_11, pars->ZERO, pars->ZERO, w[24]); 
  FFV1_3(w[6], w[0], pars->GC_11, pars->ZERO, pars->ZERO, w[25]); 
  FFV2_2(w[7], w[4], pars->GC_100, pars->ZERO, pars->ZERO, w[26]); 
  FFV1_1(w[1], w[25], pars->GC_11, pars->ZERO, pars->ZERO, w[27]); 
  FFV1_3(w[26], w[5], pars->GC_11, pars->ZERO, pars->ZERO, w[28]); 
  FFV1_1(w[5], w[25], pars->GC_11, pars->ZERO, pars->ZERO, w[29]); 
  FFV1_3(w[26], w[1], pars->GC_11, pars->ZERO, pars->ZERO, w[30]); 
  FFV1_2(w[8], w[25], pars->GC_11, pars->ZERO, pars->ZERO, w[31]); 
  FFV1_2(w[26], w[25], pars->GC_11, pars->ZERO, pars->ZERO, w[32]); 
  VVV1_1(w[25], w[16], pars->GC_10, pars->ZERO, pars->ZERO, w[33]); 
  VVV1_1(w[25], w[19], pars->GC_10, pars->ZERO, pars->ZERO, w[34]); 
  FFV2_1(w[1], w[4], pars->GC_100, pars->ZERO, pars->ZERO, w[35]); 
  FFV1_3(w[7], w[35], pars->GC_11, pars->ZERO, pars->ZERO, w[36]); 
  FFV1_2(w[7], w[25], pars->GC_11, pars->ZERO, pars->ZERO, w[37]); 
  FFV1_1(w[35], w[25], pars->GC_11, pars->ZERO, pars->ZERO, w[38]); 
  FFV2_1(w[5], w[4], pars->GC_100, pars->ZERO, pars->ZERO, w[39]); 
  FFV1_3(w[7], w[39], pars->GC_11, pars->ZERO, pars->ZERO, w[40]); 
  FFV1_1(w[39], w[25], pars->GC_11, pars->ZERO, pars->ZERO, w[41]); 
  FFV1_1(w[5], w[16], pars->GC_11, pars->ZERO, pars->ZERO, w[42]); 
  FFV1_1(w[1], w[19], pars->GC_11, pars->ZERO, pars->ZERO, w[43]); 
  FFV1_2(w[6], w[16], pars->GC_11, pars->ZERO, pars->ZERO, w[44]); 
  FFV1_2(w[6], w[19], pars->GC_11, pars->ZERO, pars->ZERO, w[45]); 
  FFV1_3(w[6], w[35], pars->GC_11, pars->ZERO, pars->ZERO, w[46]); 
  FFV1_2(w[6], w[10], pars->GC_11, pars->ZERO, pars->ZERO, w[47]); 
  FFV1_3(w[6], w[39], pars->GC_11, pars->ZERO, pars->ZERO, w[48]); 

  // Calculate all amplitudes
  // Amplitude(s) for diagram number 0
  FFV1_0(w[8], w[12], w[11], pars->GC_11, amp[0]); 
  FFV1_0(w[13], w[5], w[11], pars->GC_11, amp[1]); 
  FFV1_0(w[8], w[15], w[14], pars->GC_11, amp[2]); 
  FFV1_0(w[13], w[1], w[14], pars->GC_11, amp[3]); 
  FFV1_0(w[17], w[5], w[16], pars->GC_11, amp[4]); 
  FFV1_0(w[18], w[5], w[10], pars->GC_11, amp[5]); 
  VVV1_0(w[10], w[16], w[14], pars->GC_10, amp[6]); 
  FFV1_0(w[17], w[1], w[19], pars->GC_11, amp[7]); 
  VVV1_0(w[10], w[19], w[11], pars->GC_10, amp[8]); 
  FFV1_0(w[20], w[1], w[10], pars->GC_11, amp[9]); 
  FFV1_0(w[21], w[0], w[14], pars->GC_11, amp[10]); 
  FFV1_0(w[7], w[22], w[14], pars->GC_11, amp[11]); 
  FFV1_0(w[23], w[0], w[11], pars->GC_11, amp[12]); 
  FFV1_0(w[7], w[24], w[11], pars->GC_11, amp[13]); 
  FFV1_0(w[8], w[27], w[28], pars->GC_11, amp[14]); 
  FFV1_0(w[8], w[29], w[30], pars->GC_11, amp[15]); 
  FFV1_0(w[31], w[5], w[30], pars->GC_11, amp[16]); 
  FFV1_0(w[31], w[1], w[28], pars->GC_11, amp[17]); 
  FFV1_0(w[32], w[5], w[16], pars->GC_11, amp[18]); 
  FFV1_0(w[26], w[5], w[33], pars->GC_11, amp[19]); 
  FFV1_0(w[26], w[29], w[16], pars->GC_11, amp[20]); 
  FFV1_0(w[32], w[1], w[19], pars->GC_11, amp[21]); 
  FFV1_0(w[26], w[27], w[19], pars->GC_11, amp[22]); 
  FFV1_0(w[26], w[1], w[34], pars->GC_11, amp[23]); 
  FFV1_0(w[8], w[29], w[36], pars->GC_11, amp[24]); 
  FFV1_0(w[31], w[5], w[36], pars->GC_11, amp[25]); 
  FFV1_0(w[37], w[35], w[19], pars->GC_11, amp[26]); 
  FFV1_0(w[7], w[38], w[19], pars->GC_11, amp[27]); 
  FFV1_0(w[7], w[35], w[34], pars->GC_11, amp[28]); 
  FFV1_0(w[8], w[27], w[40], pars->GC_11, amp[29]); 
  FFV1_0(w[31], w[1], w[40], pars->GC_11, amp[30]); 
  FFV1_0(w[37], w[39], w[16], pars->GC_11, amp[31]); 
  FFV1_0(w[7], w[41], w[16], pars->GC_11, amp[32]); 
  FFV1_0(w[7], w[39], w[33], pars->GC_11, amp[33]); 
  FFV2_0(w[37], w[42], w[4], pars->GC_100, amp[34]); 
  FFV2_0(w[21], w[29], w[4], pars->GC_100, amp[35]); 
  FFV2_0(w[37], w[43], w[4], pars->GC_100, amp[36]); 
  FFV2_0(w[23], w[27], w[4], pars->GC_100, amp[37]); 
  FFV1_0(w[44], w[0], w[28], pars->GC_11, amp[38]); 
  FFV1_0(w[6], w[22], w[28], pars->GC_11, amp[39]); 
  FFV1_0(w[45], w[0], w[30], pars->GC_11, amp[40]); 
  FFV1_0(w[6], w[24], w[30], pars->GC_11, amp[41]); 
  FFV1_0(w[8], w[12], w[46], pars->GC_11, amp[42]); 
  FFV1_0(w[13], w[5], w[46], pars->GC_11, amp[43]); 
  FFV1_0(w[47], w[35], w[19], pars->GC_11, amp[44]); 
  VVV1_0(w[10], w[19], w[46], pars->GC_10, amp[45]); 
  FFV1_0(w[45], w[35], w[10], pars->GC_11, amp[46]); 
  FFV1_0(w[8], w[15], w[48], pars->GC_11, amp[47]); 
  FFV1_0(w[13], w[1], w[48], pars->GC_11, amp[48]); 
  FFV1_0(w[47], w[39], w[16], pars->GC_11, amp[49]); 
  VVV1_0(w[10], w[16], w[48], pars->GC_10, amp[50]); 
  FFV1_0(w[44], w[39], w[10], pars->GC_11, amp[51]); 
  FFV2_0(w[47], w[42], w[4], pars->GC_100, amp[52]); 
  FFV2_0(w[44], w[12], w[4], pars->GC_100, amp[53]); 
  FFV2_0(w[47], w[43], w[4], pars->GC_100, amp[54]); 
  FFV2_0(w[45], w[15], w[4], pars->GC_100, amp[55]); 
  FFV1_0(w[23], w[0], w[46], pars->GC_11, amp[56]); 
  FFV1_0(w[7], w[24], w[46], pars->GC_11, amp[57]); 
  FFV1_0(w[45], w[0], w[36], pars->GC_11, amp[58]); 
  FFV1_0(w[6], w[24], w[36], pars->GC_11, amp[59]); 
  FFV1_0(w[21], w[0], w[48], pars->GC_11, amp[60]); 
  FFV1_0(w[7], w[22], w[48], pars->GC_11, amp[61]); 
  FFV1_0(w[44], w[0], w[40], pars->GC_11, amp[62]); 
  FFV1_0(w[6], w[22], w[40], pars->GC_11, amp[63]); 

}
double P0_Sigma_sm_uxdx_mupvmduxuxdx_W_4j::matrix_uxdx_wpduxuxdx_wp_mupvm() 
{
  int i, j; 
  // Local variables
  const int ngraphs = 64; 
  const int ncolor = 6; 
  std::complex<double> ztemp; 
  std::complex<double> jamp[ncolor]; 
  // The color matrix;
  static const double denom[ncolor] = {1, 1, 1, 1, 1, 1}; 
  static const double cf[ncolor][ncolor] = {{27, 9, 9, 3, 3, 9}, {9, 27, 3, 9,
      9, 3}, {9, 3, 27, 9, 9, 3}, {3, 9, 9, 27, 3, 9}, {3, 9, 9, 3, 27, 9}, {9,
      3, 3, 9, 9, 27}};

  // Calculate color flows
  jamp[0] = +1./4. * (+amp[2] + amp[4] + std::complex<double> (0, 1) * amp[6] +
      1./3. * amp[7] + 1./3. * amp[9] + amp[10] + 1./3. * amp[12] + 1./3. *
      amp[13] + 1./3. * amp[14] + 1./9. * amp[15] + 1./9. * amp[16] + 1./3. *
      amp[17] + 1./3. * amp[18] + 1./3. * amp[20] + 1./9. * amp[21] + 1./9. *
      amp[22] + 1./9. * amp[24] + 1./9. * amp[25] + 1./9. * amp[26] + 1./9. *
      amp[27] + 1./3. * amp[29] + 1./3. * amp[30] + 1./3. * amp[31] + 1./3. *
      amp[32] + 1./3. * amp[34] + 1./3. * amp[35] + 1./9. * amp[36] + 1./9. *
      amp[37] + 1./9. * amp[40] + 1./9. * amp[41] + 1./3. * amp[44] + 1./3. *
      amp[46] + amp[47] + amp[49] + std::complex<double> (0, 1) * amp[50] +
      amp[52] + 1./3. * amp[54] + 1./3. * amp[55] + 1./3. * amp[56] + 1./3. *
      amp[57] + 1./9. * amp[58] + 1./9. * amp[59] + amp[60]);
  jamp[1] = +1./4. * (-amp[0] - 1./3. * amp[4] - 1./3. * amp[5] - amp[7] -
      std::complex<double> (0, 1) * amp[8] - 1./3. * amp[10] - 1./3. * amp[11]
      - amp[12] - 1./9. * amp[14] - 1./3. * amp[15] - 1./3. * amp[16] - 1./9. *
      amp[17] - 1./9. * amp[18] - 1./9. * amp[20] - 1./3. * amp[21] - 1./3. *
      amp[22] - 1./3. * amp[24] - 1./3. * amp[25] - 1./3. * amp[26] - 1./3. *
      amp[27] - 1./9. * amp[29] - 1./9. * amp[30] - 1./9. * amp[31] - 1./9. *
      amp[32] - 1./9. * amp[34] - 1./9. * amp[35] - 1./3. * amp[36] - 1./3. *
      amp[37] - 1./9. * amp[38] - 1./9. * amp[39] - amp[42] - amp[44] -
      std::complex<double> (0, 1) * amp[45] - 1./3. * amp[49] - 1./3. * amp[51]
      - 1./3. * amp[52] - 1./3. * amp[53] - amp[54] - amp[56] - 1./3. * amp[60]
      - 1./3. * amp[61] - 1./9. * amp[62] - 1./9. * amp[63]);
  jamp[2] = +1./4. * (-1./9. * amp[0] - 1./9. * amp[1] - 1./3. * amp[2] - 1./3.
      * amp[3] - 1./3. * amp[4] - 1./3. * amp[5] - 1./9. * amp[7] - 1./9. *
      amp[9] - 1./9. * amp[12] - 1./9. * amp[13] - amp[14] - amp[18] -
      std::complex<double> (0, 1) * amp[19] - 1./3. * amp[21] - 1./3. * amp[22]
      - 1./3. * amp[26] - 1./3. * amp[27] - amp[29] - amp[31] -
      std::complex<double> (0, 1) * amp[33] - amp[34] - 1./3. * amp[36] - 1./3.
      * amp[37] - amp[38] - 1./3. * amp[40] - 1./3. * amp[41] - 1./9. * amp[42]
      - 1./9. * amp[43] - 1./9. * amp[44] - 1./9. * amp[46] - 1./3. * amp[47] -
      1./3. * amp[48] - 1./3. * amp[49] - 1./3. * amp[51] - 1./3. * amp[52] -
      1./3. * amp[53] - 1./9. * amp[54] - 1./9. * amp[55] - 1./9. * amp[56] -
      1./9. * amp[57] - 1./3. * amp[58] - 1./3. * amp[59] - amp[62]);
  jamp[3] = +1./4. * (+1./3. * amp[0] + 1./3. * amp[1] + 1./9. * amp[2] + 1./9.
      * amp[3] + 1./9. * amp[4] + 1./9. * amp[5] + 1./3. * amp[7] + 1./3. *
      amp[9] + 1./9. * amp[10] + 1./9. * amp[11] + amp[15] + 1./3. * amp[18] +
      1./3. * amp[20] + amp[21] + std::complex<double> (0, 1) * amp[23] +
      amp[24] + amp[26] + std::complex<double> (0, 1) * amp[28] + 1./3. *
      amp[31] + 1./3. * amp[32] + 1./3. * amp[34] + 1./3. * amp[35] + amp[36] +
      1./3. * amp[38] + 1./3. * amp[39] + amp[40] + 1./3. * amp[42] + 1./3. *
      amp[43] + 1./3. * amp[44] + 1./3. * amp[46] + 1./9. * amp[47] + 1./9. *
      amp[48] + 1./9. * amp[49] + 1./9. * amp[51] + 1./9. * amp[52] + 1./9. *
      amp[53] + 1./3. * amp[54] + 1./3. * amp[55] + amp[58] + 1./9. * amp[60] +
      1./9. * amp[61] + 1./3. * amp[62] + 1./3. * amp[63]);
  jamp[4] = +1./4. * (+1./3. * amp[0] + 1./3. * amp[1] + amp[3] + amp[5] -
      std::complex<double> (0, 1) * amp[6] + amp[11] + 1./3. * amp[12] + 1./3.
      * amp[13] + 1./3. * amp[14] + amp[16] + 1./3. * amp[17] + amp[22] -
      std::complex<double> (0, 1) * amp[23] + amp[25] + amp[27] -
      std::complex<double> (0, 1) * amp[28] + 1./3. * amp[29] + 1./3. * amp[30]
      + amp[37] + 1./3. * amp[38] + 1./3. * amp[39] + amp[41] + 1./3. * amp[42]
      + 1./3. * amp[43] + amp[48] - std::complex<double> (0, 1) * amp[50] +
      amp[51] + amp[53] + 1./3. * amp[56] + 1./3. * amp[57] + amp[59] + amp[61]
      + 1./3. * amp[62] + 1./3. * amp[63]);
  jamp[5] = +1./4. * (-amp[1] - 1./3. * amp[2] - 1./3. * amp[3] +
      std::complex<double> (0, 1) * amp[8] - amp[9] - 1./3. * amp[10] - 1./3. *
      amp[11] - amp[13] - 1./3. * amp[15] - 1./3. * amp[16] - amp[17] +
      std::complex<double> (0, 1) * amp[19] - amp[20] - 1./3. * amp[24] - 1./3.
      * amp[25] - amp[30] - amp[32] + std::complex<double> (0, 1) * amp[33] -
      amp[35] - amp[39] - 1./3. * amp[40] - 1./3. * amp[41] - amp[43] +
      std::complex<double> (0, 1) * amp[45] - amp[46] - 1./3. * amp[47] - 1./3.
      * amp[48] - amp[55] - amp[57] - 1./3. * amp[58] - 1./3. * amp[59] - 1./3.
      * amp[60] - 1./3. * amp[61] - amp[63]);

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



