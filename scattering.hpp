#ifndef SCATTERING_H
#define SCATTERING_H

#include <iostream>
#include <cstdlib>
#include <boost/math/special_functions/bessel.hpp>
#include <complex>
using namespace std;

#include "potentials.hpp"
#include "numerov.hpp"
#include "writeout.hpp"
#include "constant.hpp"

// Calculation of the scattering amplitude for single-channel potential scattering.

complex<double> Smatrix(const CentralPotentials pot, const double energy, const int l, const double h2over2mu, const vector<double> & parameters, 
	const int nmesh, const double mesh);
#endif