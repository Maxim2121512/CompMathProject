#include "CartesianCoords.h"

double CartesianCoords::getX(){
    return this->x;
}

double CartesianCoords::getY(){
    return this->y;
}

double CartesianCoords::getZ(){
    return this->z;
}

void CartesianCoords::setX(double x){
    this->x = x;
}

void CartesianCoords::setY(double y){
    this->y = y;
}

void CartesianCoords::setZ(double z){
    this->z = z;
}

void CartesianCoords::setAllCoords(double x, double y, double z){
    this->x = x;
    this->y = y;
    this->z = z;
}

double CartesianCoords::euclidianNorm(){
    return sqrt(x * x + y * y + z * z);
}

CartesianCoords operator+(CartesianCoords c1, CartesianCoords c2){
    CartesianCoords result;
    result.x = c1.x + c2.x;
    result.y = c1.y + c2.y;
    result.z = c1.z + c2.z;
    return result;
}

CartesianCoords operator-(CartesianCoords c1, CartesianCoords c2){
    CartesianCoords result;
    result.x = c1.x - c2.x;
    result.y = c1.y - c2.y;
    result.z = c1.z - c2.z;
    return result;
}

CartesianCoords operator*(CartesianCoords c1, CartesianCoords c2){
    CartesianCoords result;
    result.x = c1.x * c2.x;
    result.y = c1.y * c2.y;
    result.z = c1.z * c2.z;
    return result;
}

CartesianCoords operator*(double scalar, CartesianCoords c1){
    CartesianCoords result;
    result.x = c1.x * scalar;
    result.y = c1.y * scalar;
    result.z = c1.z * scalar;
    return result;
}

CartesianCoords operator/(CartesianCoords c1, double scalar){
    CartesianCoords result;
    result.x = c1.x / scalar;
    result.y = c1.y / scalar;
    result.z = c1.z / scalar;
    return result;
}

CartesianCoords operator/(CartesianCoords c1, CartesianCoords c2){
    CartesianCoords result;
    result.x = c1.x / c2.x;
    result.y = c1.y / c2.y;
    result.z = c1.z / c2.z;
    return result;
}
