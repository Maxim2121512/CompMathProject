#pragma once

#include <math.h>

class CartesianCoords{
private:

    double x = 0;
    double y = 0;
    double z = 0;

public:

    CartesianCoords() = default;
    CartesianCoords(double x, double y, double z): x(x), y(y), z(z) {};

    double getX();
    double getY();
    double getZ();

    void setX(double x);
    void setY(double y);
    void setZ(double z);
    void setAllCoords(double x, double y, double z);

    double euclidianNorm();

    friend CartesianCoords operator+(CartesianCoords c1, CartesianCoords c2);
    friend CartesianCoords operator-(CartesianCoords c1, CartesianCoords c2);
    friend CartesianCoords operator*(CartesianCoords c1, CartesianCoords c2);
    friend CartesianCoords operator*(double scalar, CartesianCoords c1);
    friend CartesianCoords operator/(CartesianCoords c1, CartesianCoords c2);
    friend CartesianCoords operator/(CartesianCoords c1, double scalar);

    ~CartesianCoords() = default;
};