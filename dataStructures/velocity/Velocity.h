#pragma once

#include <math.h>

class Velocity{
private:
    double vx = 0;
    double vy = 0;
    double vz = 0;

public:
    Velocity() = default;
    Velocity(double vx, double vy, double vz): vx(vx), vy(vy), vz(vz) {};

    double getVx();
    double getVy();
    double getVz();

    void setVx(double vx);
    void setVy(double vy);
    void setVz(double vz);
    void setAllVelocities(double vx, double vy, double vz);

    double euclidianNorm();

    friend Velocity operator+(Velocity v1, Velocity v2);
    friend Velocity operator-(Velocity v1, Velocity v2);
    friend Velocity operator*(Velocity v1, Velocity v2);
    friend Velocity operator*(double scalar, Velocity v1);
    friend Velocity operator/(Velocity v1, Velocity v2);
    friend Velocity operator/(Velocity v1, double scalar);

    ~Velocity() = default;
};