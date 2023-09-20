#pragma once

#include "coords/EquatorialCoords.h"
#include "coords/CartesianCoords.h"
#include "velocity/Velocity.h"
#include "date/Date.h"
#include "Matrix.h"


class ModelVector{
private:

    EquatorialCoords equatorialCoords;
    CartesianCoords cartesianCoords;
    Velocity velocity;
    Date date;

    Matrix dx_db = Matrix(6, 6);
    Matrix dg_dx = Matrix(2, 6);
    Matrix dr_db = Matrix(2, 6);

public:
    ModelVector() = default;

    void setEquatorialCoords(EquatorialCoords coords);
    void setEquatorialCoords(double Ra, double Decl);
    void setCartesianCoords(CartesianCoords coords);
    void setVelocity(Velocity vel);
    void setDate(Date date);
    void set_dx_db(Matrix dx_db);
    void set_dg_dx(Matrix dg_dx);
    void set_dr_db(Matrix dr_db);
    double getCartesianX();
    double getCartesianY();
    double getCartesianZ();
    EquatorialCoords getEquatorial();
    CartesianCoords getCartesian();
    Velocity getVelocity();
    Date getDate();
    Matrix& get_dx_db();
    Matrix& get_dg_dx();
    Matrix& get_dr_db();

    ~ModelVector() = default;
};