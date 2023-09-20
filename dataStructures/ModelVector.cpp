#include "ModelVector.h"


void ModelVector::setCartesianCoords(CartesianCoords coords){
    this->cartesianCoords = coords;
}

double ModelVector::getCartesianX(){
    return this->cartesianCoords.getX()/100;
}

double ModelVector::getCartesianY(){
    return this->cartesianCoords.getY()/100;
}

double ModelVector::getCartesianZ(){
    return this->cartesianCoords.getZ()/100;
}

void ModelVector::setEquatorialCoords(EquatorialCoords coords){
    this->equatorialCoords = coords;
}

void ModelVector::setDate(Date date){
    this->date = date;
}

void ModelVector::setEquatorialCoords(double Ra, double Decl){
    this->equatorialCoords.setRa(Ra);
    this->equatorialCoords.setDecl(Decl);
}
void ModelVector::setVelocity(Velocity vel){
    this->velocity = velocity;
}

void ModelVector::set_dx_db(Matrix dx_db){
    this->dx_db = dx_db;
}

void ModelVector::set_dr_db(Matrix dr_db){
    this->dr_db = dr_db;
}

void ModelVector::set_dg_dx(Matrix dg_dx){
    this->dg_dx = dg_dx;
}

CartesianCoords ModelVector::getCartesian(){
    return this->cartesianCoords;
}

EquatorialCoords ModelVector::getEquatorial(){
    return this->equatorialCoords;
}

Velocity ModelVector::getVelocity(){
    return this->velocity;
}

Date ModelVector::getDate(){
    return this->date;
}

Matrix& ModelVector::get_dx_db(){
    return this->dx_db;
}

Matrix& ModelVector::get_dr_db(){
    return this->dr_db;
}

Matrix& ModelVector::get_dg_dx(){
    return this->dg_dx;
}

