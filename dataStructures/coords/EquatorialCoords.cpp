#include "EquatorialCoords.h"

double EquatorialCoords::getDecl(){
    return this->Decl;
}

double EquatorialCoords::getRa(){
    return this->Ra;
}

void EquatorialCoords::setRa(double Ra){
    this->Ra = Ra;
}

void EquatorialCoords::setDecl(double Decl){
    this->Decl = Decl;
}

// theta - Ra from -pi  to pi
// phi - Decl from -pi/2 to pi/2
void EquatorialCoords::setEquatorial(double x, double y, double z){
    double newX = x*1000 + X_BH;
    double newY = y*1000 + Y_BH;
    double newZ = z*1000 + Z_BH;
    double d = sqrt(newX * newX + newY * newY);


    double RA = atan2(newY , newX);
    double DECL = atan(newZ / d);

    

    this->Ra = (RA - RA_BH) * 180/PI * 3600;
    this->Decl = (DECL - DECL_BH) * 180/PI * 3600;
}