#include "potentials.hpp"

double CentralPotential (const CentralPotentials pot, const double r, const vector<double> & parameters) {
	double value;
	switch(pot){
		case WS: {
			if (parameters.size() != 3) {cerr << "wrong number of parameters for Woods-Saxon." << endl; throw exception();}
			value = WoodsSaxon(r,parameters.at(0),parameters.at(1),parameters.at(2));
			break;
		}
		case SW: {
			if (parameters.size() != 2) {cerr << "wrong number of parameters for SphericalWell." << endl; throw exception();}
			value = SphericalWell(r,parameters.at(0),parameters.at(1));
			break;
		}
	}
	return value;
};


double WoodsSaxon(const double r, const double V0, const double a, const double R) {
	double x = 1.0 + exp((r-R)/a);
	return -V0/x;
};

// finite spherical well
double SphericalWell(const double r, const double V, const double R) {
	if (r <= R) return -V;
	else return 0.0;
};


 double Centrifugal(const int l, const double r) {
	if (l == 0) return 0.0;
	else return l*(l+1.0)/(r*r);
}