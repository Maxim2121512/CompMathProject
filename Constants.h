#pragma once
#include <math.h>


const double PI = 3.141592653589793;
const double C = 300000.0; // km/s
const double M_BH = 8.254018e+36; //kg
const double M_S55 = 2.983e+31; //kg
const double G = 6.6743e-20; //kg^-1 * km^3 * s^-2
const double DISTANCE = 2.4685e+17;
const double RA_BH = 0.0840132701; // rad
const double DECL_BH = -0.5062807460953851; // rad
const double X_BH = DISTANCE * cos(DECL_BH) * cos(RA_BH); // km
const double Y_BH = DISTANCE * cos(DECL_BH) * sin(RA_BH); // km
const double Z_BH = DISTANCE * sin(DECL_BH); // km
