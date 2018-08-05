#ifndef CONSTANT_H
#define CONSTANT_H
#include <complex>


// mathematical constants
const double PI = 3.141592653590;
const complex<double> IM = complex<double>(0.0,1.0);

// physical constants
const double H = 6.6207e-34; // Joule-seconds = kg
const double HBAR = 1.0545718e-34; // Joule-seconds
const double SPEED_OF_LIGHT = 2.99792e8; // m/s

const double NEUTRON_MASS = 939.56536; // MeV/c^2
// conversions
const double MEV_PER_JOULE = 6.2415091e12; // 1 J = x MeV  x = J/MeV




#endif