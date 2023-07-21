#include "Velocity.h"



double Velocity::getVx(){
    return this->vx;
}

double Velocity::getVy(){
    return this->vy;
}

double Velocity::getVz(){
    return this->vz;
}

void Velocity::setVx(double vx){
    this->vx = vx;
}

void Velocity::setVy(double vy){
    this->vy = vy;
}

void Velocity::setVz(double vz){
    this->vz = vz;
}

void Velocity::setAllVelocities(double vx, double vy, double vz){
    this->vx = vx;
    this->vy = vy;
    this->vz = vz;
}

double Velocity::euclidianNorm(){
    return sqrt(vx * vx + vy * vy + vz * vz);
}

Velocity operator+(Velocity v1, Velocity v2){
    Velocity result;
    result.vx = v1.vx + v2.vx;
    result.vy = v1.vy + v2.vy;
    result.vz = v1.vz + v2.vz;
    return result;
}

Velocity operator-(Velocity v1, Velocity v2){
    Velocity result;
    result.vx = v1.vx - v2.vx;
    result.vy = v1.vy - v2.vy;
    result.vz = v1.vz - v2.vz;
    return result;
}

Velocity operator*(Velocity v1, Velocity v2){
    Velocity result;
    result.vx = v1.vx * v2.vx;
    result.vy = v1.vy * v2.vy;
    result.vz = v1.vz * v2.vz;
    return result;
}

Velocity operator*(double scalar, Velocity v1){
    Velocity result;
    result.vx = v1.vx * scalar;
    result.vy = v1.vy * scalar;
    result.vz = v1.vz * scalar;
    return result;
}

Velocity operator/(Velocity v1, Velocity v2){
    Velocity result;
    result.vx = v1.vx / v2.vx;
    result.vy = v1.vy / v2.vy;
    result.vz = v1.vz / v2.vz;
    return result;
}

Velocity operator/(Velocity v1, double scalar){
    Velocity result;
    result.vx = v1.vx / scalar;
    result.vy = v1.vy / scalar;
    result.vz = v1.vz / scalar;
    return result;
}
