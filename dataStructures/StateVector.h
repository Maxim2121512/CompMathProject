#pragma once

#include "coords/CartesianCoords.h"
#include "coords/EquatorialCoords.h"
#include "velocity/Velocity.h"
#include "date/Date.h"
#include "Matrix.h"
#include <vector>
class StateVector{
private:
    CartesianCoords cartesianCoords;
    EquatorialCoords equatorialCoords;
    Velocity velocity;

    Date date;

    Matrix df_dx = Matrix(6,6);
    Matrix dx_db = Matrix(6,6);

public:
    StateVector() = default;
    StateVector(CartesianCoords coords, Velocity velocity): cartesianCoords(coords), velocity(velocity){};
    StateVector(double x, double y, double z, double vx, double vy, double vz);

    void setCartesianCoords(CartesianCoords coords);
    void setCartesianCoords(double x, double y, double z);
    void setVelocity(Velocity velocity);
    void setVelocity(double vx, double vy, double vz);
    void setEquatorialCoords();
    void setState(CartesianCoords coords, Velocity Velocity);
    void setState(double x, double y, double z, double vx, double vy, double vz);
    void set_dx_db(Matrix dx_db);
    void setDate(Date date);

    EquatorialCoords getEquatorialCoords();
    CartesianCoords getCartesianCoords();
    Velocity getVelocity();
    Date getDate();
    Matrix& get_df_dx();
    Matrix& get_dx_db();

    friend StateVector operator+(StateVector s1, StateVector s2);
    friend StateVector operator-(StateVector s1, StateVector s2);
    friend StateVector operator*(StateVector s1, StateVector s2);
    friend StateVector operator*(double scalar, StateVector s1);
    friend StateVector operator/(StateVector s1, StateVector s2);
    friend StateVector operator/(StateVector s1, double scalar);

    ~StateVector() = default;
};