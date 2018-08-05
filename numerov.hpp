#ifndef NUMEROV_H
#define NUMEROV_H

#include <cstdlib>
#include <cmath>
#include <complex>

using namespace std;

double NumerovStep(const double f2, const double f1, const double psi1, 
	const double f0, const double psi0, const double dx);

complex<double> NumerovStep(const complex<double> f2, const complex<double> f1, const complex<double> psi1, 
	const complex<double> f0, const complex<double> psi0, const double dx);

#endif