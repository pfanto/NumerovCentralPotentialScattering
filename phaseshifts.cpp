#include "phaseshifts.hpp"

// test case for a p-wave neutron scattering from the heavy nucleus 194-Pt

int main(int argc, char * argv[]) {
	cout.setf(ios::scientific,ios::floatfield);
	cout << setprecision(4);
	cout << "3D scattering phase shift calculation" << endl;
	CentralPotentials pot = WS;
	double V0 = 44.54; 
	double a = 0.67; 
	double R = 1.27*pow(194.0,1./3.);

	vector<double> parameters (3);
	parameters.at(0) = V0;
	parameters.at(1) = a;
	parameters.at(2) = R;

	cout << "Potential type = " << pot << endl;
	PrintVector("V0 (MeV), a (fm), R (fm) = ", parameters);

	const int nmesh = 75;
	const double mesh = 0.2;

	// energy
	double energy = 8.0e-3; // MeV
	int l = 1;

	cout << "energy (MeV) = " << energy << endl;

	const double h2over2mu = HBAR*MEV_PER_JOULE*HBAR*MEV_PER_JOULE*SPEED_OF_LIGHT*SPEED_OF_LIGHT*1e30/(2.0*NEUTRON_MASS); // Mev^2 * fm^2
	cout << "h2over2mu = " << h2over2mu << endl;

	complex<double> smat = Smatrix(pot, energy, l, h2over2mu, parameters, nmesh, mesh);
	cout << "smat = " << smat << endl;

	double delta = 0.5*arg(smat);
	cout << "delta = " << delta << endl;

}