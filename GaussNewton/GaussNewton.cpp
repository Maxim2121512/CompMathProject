#include "GaussNewton.h"

void GaussNewton::calculate_dg_dx(ModelVector& modelVector){
    double x = modelVector.getCartesian().getX();
    double y = modelVector.getCartesian().getY();
    double z = modelVector.getCartesian().getZ();

    modelVector.get_dg_dx().setElem(-1 * y / (x * x + y * y),0, 0);
    modelVector.get_dg_dx().setElem(x / (x * x + y * y), 0, 1);
    modelVector.get_dg_dx().setElem(-1 * (x * z) / (std::sqrt(x * x + y * y) * (x * x + y * y + z * z)) , 1, 0);
    modelVector.get_dg_dx().setElem(-1 * (y * z) / (std::sqrt(x * x + y * y) * (x * x + y * y + z * z)), 1, 1);
    modelVector.get_dg_dx().setElem(((x * x + y * y)) / (std::sqrt(x * x + y * y) * (x * x + y * y + z * z)), 1, 2);

}

void GaussNewton::calculate_dr_db(ModelVector& modelVector){
    modelVector.set_dr_db(-1 * modelVector.get_dg_dx() * modelVector.get_dx_db());
}

StateVector GaussNewton::GaussNewtonAlg(StateVector x0, Matrix* A, Matrix* R, double* W){
    StateVector newX0;
    Matrix gradient_f = (A->transpose()) * (W) * (*A);
    Matrix f_b = A->transpose() * (W) * (*R);
    Matrix solutionSystem = solveSystem(&gradient_f, &f_b);
    newX0.setCartesianCoords(x0.getCartesianCoords().getX() - solutionSystem.getElem(0,0), 
    x0.getCartesianCoords().getY() - solutionSystem.getElem(1, 0),
    x0.getCartesianCoords().getZ() - solutionSystem.getElem(2, 0));

    newX0.setVelocity(x0.getVelocity().getVx() - solutionSystem.getElem(3, 0),
    x0.getVelocity().getVy() - solutionSystem.getElem(4, 0),
    x0.getVelocity().getVz() - solutionSystem.getElem(5, 0));

    return newX0;
}

Matrix GaussNewton::solveSystem(Matrix* grad_f, Matrix* f_b){
    Matrix decomposedMatrix = f_b->CholeskyDecomposition(*grad_f);
    Matrix y(decomposedMatrix.getNumRows(), f_b->getNumColumns());

    for(int i = 0; i < decomposedMatrix.getNumRows(); i++){
        double sum = 0;

        for(int j = 0; j < i; j++){
            sum += decomposedMatrix.getElem(i,j) * y.getElem(j, 0);
        }

        y.setElem((f_b->getElem(i,0) - sum) / decomposedMatrix.getElem(i,i), i, 0);
        
    }

    decomposedMatrix = decomposedMatrix.transpose();

    Matrix solutionSystem(decomposedMatrix.getNumRows(), y.getNumColumns());

    for(int i = decomposedMatrix.getNumRows() - 1; i > -1; i--){
        double sum = 0;

        for(int j = i; j < decomposedMatrix.getNumRows(); j++){
            sum += decomposedMatrix.getElem(i, j) * solutionSystem.getElem(j,0);
        }

        solutionSystem.setElem((y.getElem(i,0) - sum) / decomposedMatrix.getElem(i,i), i, 0);
        
    }

    return solutionSystem;
}