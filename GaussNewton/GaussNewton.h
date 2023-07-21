#pragma once

#include "../dataStructures/ModelVector.h"
#include "../dataStructures/StateVector.h"

class GaussNewton{
public:
    GaussNewton() = default;
    void calculate_dg_dx(ModelVector& modelVector);
    void calculate_dr_db(ModelVector& ModelVector);


    StateVector GaussNewtonAlg(StateVector x0, Matrix* A, Matrix* R, double* W);

    Matrix solveSystem(Matrix* gradient_f, Matrix* f_b);
    ~GaussNewton() = default;
};