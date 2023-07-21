#pragma once

#include "../../Constants.h"

class EquatorialCoords{
private: 
    double Ra = 0;
    double Decl = 0;

public:
    EquatorialCoords() = default;
    EquatorialCoords(double Ra, double Decl): Ra(Ra), Decl(Decl){}

    double getRa();
    double getDecl();

    void setRa(double Ra);
    void setDecl(double Decl);
    void setEquatorial(double x, double y, double z);

    ~EquatorialCoords() = default;
};