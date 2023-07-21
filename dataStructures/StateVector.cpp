#include "StateVector.h"


StateVector::StateVector(double x, double y, double z, double vx, double vy, double vz){
    this->cartesianCoords.setAllCoords(x, y, z);
    this->velocity.setAllVelocities(vx, vy, vz);
}

void StateVector::setCartesianCoords(CartesianCoords coords){
    this->cartesianCoords = coords;
}

void StateVector::setCartesianCoords(double x, double y, double z){
    this->cartesianCoords.setAllCoords(x, y, z); 
}

void StateVector::setVelocity(Velocity velocity){
    this->velocity = velocity;
}

void StateVector::setVelocity(double vx, double vy, double vz){
    this->velocity.setAllVelocities(vx, vy, vz);
}

void StateVector::setEquatorialCoords(){
    this->equatorialCoords.setEquatorial(this->cartesianCoords.getX(), this->cartesianCoords.getY(), this->cartesianCoords.getZ());
}

void StateVector::setState(CartesianCoords coords, Velocity velocity){
    this->cartesianCoords = coords;
    this->velocity = velocity;
}

void StateVector::setState(double x, double y, double z, double vx, double vy, double vz){
    this->cartesianCoords.setAllCoords(x, y, z);
    this->velocity.setAllVelocities(vx, vy, vz);
}

void StateVector::set_dx_db(Matrix dx_db){
    this->dx_db = dx_db;
}

void StateVector::setDate(Date date){
    this->date = date;
}

CartesianCoords StateVector::getCartesianCoords(){
    return this->cartesianCoords;
}

Velocity StateVector::getVelocity(){
    return this->velocity;
}

EquatorialCoords StateVector::getEquatorialCoords(){
    return this->equatorialCoords;
}

Date StateVector::getDate(){
    return this->date;
}

Matrix& StateVector::get_df_dx(){
    return this->df_dx;
}

Matrix& StateVector::get_dx_db(){
    return this->dx_db;
}

StateVector operator+(StateVector s1, StateVector s2){
    StateVector result;
    result.cartesianCoords = s1.cartesianCoords + s2.cartesianCoords;
    result.velocity = s1.velocity + s2.velocity;
    result.df_dx = s1.df_dx + s2.df_dx;
    result.dx_db = s1.dx_db + s2.dx_db;
    return result;
}

StateVector operator-(StateVector s1, StateVector s2){
    StateVector result;
    result.cartesianCoords = s1.cartesianCoords - s2.cartesianCoords;
    result.velocity = s1.velocity - s2.velocity;
    result.df_dx = s1.df_dx - s2.df_dx;
    result.dx_db = s1.dx_db - s2.dx_db;
    return result;
}

StateVector operator*(StateVector s1, StateVector s2){
    StateVector result;
    result.cartesianCoords = s1.cartesianCoords * s2.cartesianCoords;
    result.velocity = s1.velocity * s2.velocity;
    result.df_dx = s1.df_dx * s2.df_dx;
    result.dx_db = s1.dx_db * s2.dx_db;
    return result;
}

StateVector operator*(double scalar, StateVector s1){
    StateVector result;
    result.cartesianCoords = scalar * s1.cartesianCoords;
    result.velocity = scalar * s1.velocity;
    result.df_dx = scalar * s1.df_dx;
    result.dx_db = scalar * s1.dx_db;
    return result;
}

StateVector operator/(StateVector s1, StateVector s2){
    StateVector result;
    result.cartesianCoords = s1.cartesianCoords / s2.cartesianCoords;
    result.velocity = s1.velocity / s2.velocity;
    return result;
}

StateVector operator/(StateVector s1, double scalar){
    StateVector result;
    result.cartesianCoords = s1.cartesianCoords / scalar;
    result.velocity = s1.velocity / scalar;
    return result;
}