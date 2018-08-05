#include "scattering.hpp"



complex<double> Smatrix(const CentralPotentials pot, const double energy, const int l, const double h2over2mu, const vector<double> & parameters, 
	const int nmesh, const double mesh) {
	// check inputs
	cout << "pot = " << pot << endl;
	cout << "nmesh, mesh = " << nmesh << " " << mesh << endl;
	cout << "energy, l, h2over2mu = " << energy << " " << l << " " << h2over2mu << endl;
	PrintVector("parameters = ",parameters);

	double kc = sqrt(energy/h2over2mu);

	cout << "kc = " << kc << endl; // 1/fm

	double r0,r1,r2; // spatial positions
	r0 = 0.0;
	r1 = r0 + mesh;
	r2 = r1 + mesh;

	double u0,u1,u2; // wavefunction
	u0 = 0.0;
	u1 = 1.0;

	double UMAX = abs(u1);
	//cout << "# r   u " << endl;
	//cout << r0 << " " << u0 << endl;
	//cout << r1 << " " << u1 << endl;

	// integrate wavefunction from origin out to final position

	for (int i = 0; i < nmesh-1; i++) {
		if (i > 0) {
			r0 = r1*1.0; r1 = r2*1.0; r2 += mesh;
			u0 = u1*1.0;
			u1 = u2*1.0;
		}
	
		double pot0 = CentralPotential(pot,r0,parameters);
		double f0 = kc*kc - pot0/h2over2mu;
		if (l > 0) f0 -= Centrifugal(l,r0);
		if (r0 == 0.0) f0 = -1.0e12;

		double pot1 = CentralPotential(pot,r1,parameters);
		double f1 = kc*kc - pot1/h2over2mu;
		if (l > 0) f1 -= Centrifugal(l,r1);

		double pot2 = CentralPotential(pot,r2,parameters);
		double f2 = kc*kc - pot2/h2over2mu;
		if (l > 0) f2 -= Centrifugal(l,r2);

		u2 = NumerovStep(f2,f1,u1,f0,u0,mesh);
		//cout << r2 << " " << u2 << endl;

		if (abs(u2) > UMAX) UMAX = abs(u2);
	}

	// get S matrix from asymptotic form of scattering wavefunction

	u1 /= UMAX; u2 /= UMAX;
	double M = r2*u1/(r1*u2);

	double j1 = boost::math::sph_bessel((double) l,kc*r1);
	double j2 = boost::math::sph_bessel((double) l,kc*r2);

	double n1 = boost::math::sph_neumann((double) l,kc*r1);
	double n2 = boost::math::sph_neumann((double) l,kc*r2);

	double tand = (M*j2 - j1)/(M*n2-n1);

	double delta = atan(tand);

	complex<double> smat = exp(2.0*IM*delta);
	cout << "smat = " << smat << endl;

	return smat;

}