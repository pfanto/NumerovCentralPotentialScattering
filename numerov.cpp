#include "numerov.hpp"

//*************************************//
/* Numerov algorithm steps for purely real potentials or complex potentials. */
//*************************************//

double NumerovStep(const double f2, const double f1, const double psi1, 
	const double f0, const double psi0, const double dx) {
	double phi0 = (1.0 + dx*dx*f0/12.0)*psi0;
	double phi1 = (1.0 + dx*dx*f1/12.0)*psi1;
	double phi2 = 2.0*phi1 - phi0 - dx*dx*f1*psi1;
	double denom2 = 1.0 + dx*dx*f2/12.0;
	double psi2 = phi2/denom2;
	return psi2;
}

complex<double> NumerovStep(const complex<double> f2, const complex<double> f1, const complex<double> psi1, 
	const complex<double> f0, const complex<double> psi0, const double dx) {

	complex<double> phi0 = (1.0 + dx*dx*f0/12.0)*psi0;
	complex<double> phi1 = (1.0 + dx*dx*f1/12.0)*psi1;
	complex<double> phi2 = 2.0*phi1 - phi0 - dx*dx*f1*psi1;
	complex<double> denom2 = 1.0 + dx*dx*f2/12.0;
	complex<double> psi2 = phi2/denom2;
	return psi2;
}