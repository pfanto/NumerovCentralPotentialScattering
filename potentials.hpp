#ifndef POTENTIALS_H
#define POTENTIALS_H

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;


// common forms for 3D central potentials

typedef enum {WS = 0, SW = 1} CentralPotentials;

double CentralPotential (const CentralPotentials pot, const double r, const vector<double> & parameters);


// Wood-Saxon potential.  Common in nuclear physics
// See Bohr and Mottelson, Nuclear Structure Vol 1.
double WoodsSaxon(const double r, const double V0, const double a, const double R);

// finite spherical well
double SphericalWell(const double r, const double V, const double R);

double Centrifugal(const int l,const double r);

#endif