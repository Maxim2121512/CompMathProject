#include "Integrator.h"
#include <iostream>

StateVector Integrator::rsFunction(StateVector state){
    StateVector newState;
    
    double p = -(G * M_BH) / 
    (C * C * state.getCartesianCoords().euclidianNorm() * state.getCartesianCoords().euclidianNorm() * state.getCartesianCoords().euclidianNorm());

    double dotProduct = state.getVelocity().getVx() * state.getCartesianCoords().getX() + 
    state.getVelocity().getVy() * state.getCartesianCoords().getY() + 
    state.getVelocity().getVz() * state.getCartesianCoords().getZ();

    Velocity newVelocity;
    CartesianCoords newCartesian;

    newVelocity.setVx(p * (state.getCartesianCoords().getX() * 
    (pow(C, 2) - 4 * (G * M_BH)/state.getCartesianCoords().euclidianNorm() + 
    state.getVelocity().euclidianNorm()) - 4 * state.getVelocity().getVx() * dotProduct));

    newCartesian.setX(state.getVelocity().getVx());


    newVelocity.setVy(p * (state.getCartesianCoords().getY() * 
    (pow(C, 2) - 4 * (G * M_BH)/state.getCartesianCoords().euclidianNorm() + 
    state.getVelocity().euclidianNorm()) - 4 * state.getVelocity().getVy() * dotProduct));

    newCartesian.setY(state.getVelocity().getVy());

    newVelocity.setVz(p * (state.getCartesianCoords().getZ() * 
    (pow(C, 2) - 4 * (G * M_BH)/state.getCartesianCoords().euclidianNorm() + 
    state.getVelocity().euclidianNorm()) - 4 * state.getVelocity().getVz() * dotProduct));

    newCartesian.setZ(state.getVelocity().getVz());

    newState.setState(newCartesian, newVelocity);

    this->calculatePartialDerivates(state, newState.get_df_dx());

   
    Matrix dx_db = newState.get_df_dx() * state.get_dx_db();
    newState.set_dx_db(dx_db);

    return newState;
}


void Integrator::calculatePartialDerivates(StateVector& state, Matrix& partialDerivates){
    // calculate df/dx
    partialDerivates.setElem(1, 0, 3);
    partialDerivates.setElem(1, 1, 4);
    partialDerivates.setElem(1, 2, 5);

    double len = pow(state.getCartesianCoords().euclidianNorm(), 5.0);

    partialDerivates.setElem( ((G * M_BH) * 
    (2 * pow(state.getCartesianCoords().getX(),2) - pow(state.getCartesianCoords().getY(), 2) - pow(state.getCartesianCoords().getZ(), 2))) 
    / len , 3, 0);

    partialDerivates.setElem( 3 * ((G * M_BH) * 
    (state.getCartesianCoords().getX() * state.getCartesianCoords().getY())) 
    / len , 3, 1);

    partialDerivates.setElem( 3 * ((G * M_BH) * 
    (state.getCartesianCoords().getX() * state.getCartesianCoords().getZ())) 
    / len , 3, 2);

    partialDerivates.setElem( 3 * ((G * M_BH) * 
    (state.getCartesianCoords().getX() * state.getCartesianCoords().getY())) 
    / len , 4, 0);

    partialDerivates.setElem( -((G * M_BH) * 
    (pow(state.getCartesianCoords().getX(),2) - 2 * pow(state.getCartesianCoords().getY(), 2) + pow(state.getCartesianCoords().getZ(), 2))) 
    / len , 4, 1);

    partialDerivates.setElem( 3 * ((G * M_BH) * 
    (state.getCartesianCoords().getY() * state.getCartesianCoords().getZ())) 
    / len , 4, 2);

    partialDerivates.setElem( 3 * ((G * M_BH) * 
    (state.getCartesianCoords().getX() * state.getCartesianCoords().getZ())) 
    / len , 5, 0);

    partialDerivates.setElem( 3 * ((G * M_BH) * 
    (state.getCartesianCoords().getY() * state.getCartesianCoords().getZ())) 
    / len , 5, 1);

    partialDerivates.setElem( -((G * M_BH) * 
    (pow(state.getCartesianCoords().getX(),2) + pow(state.getCartesianCoords().getY(), 2) - 2 * pow(state.getCartesianCoords().getZ(), 2))) 
    / len , 5, 2);
}


std::pair<std::vector<StateVector>, std::vector<ModelVector>> Integrator::RK4(StateVector initialState){
    StateVector k1, k2, k3, k4;
    
    std::vector<StateVector> result;
    std::vector<ModelVector> modelData;


    StateVector lastState = initialState;
    Date date((long long) currentTime);
    lastState.setEquatorialCoords();
    lastState.setDate(date);
    lastState.set_dx_db(lastState.get_dx_db().getIdentityMatrix());
    result.push_back(lastState);

    int i = 0;
    while(currentTime < endTime){
        
        k1 = rsFunction(lastState);
        k2 = rsFunction(lastState + h * (0.5 * k1));
        k3 = rsFunction(lastState + h * (0.5 * k2));
        k4 = rsFunction(lastState + h * k3);

        lastState = lastState + h * (1.0 / 6.0) * (k1 + 2.0 * k2 + 2.0 * k3 + k4);
        
        lastState.setEquatorialCoords();
        Date date((long long) currentTime);
        lastState.setDate(date);
        result.push_back(lastState);

        


        if((i < times.size()) && (times[i] == currentTime)){
            ModelVector modelVec;
            modelVec.setCartesianCoords(lastState.getCartesianCoords());
            modelVec.setDate(lastState.getDate());
            modelVec.setEquatorialCoords(lastState.getEquatorialCoords());
            modelVec.setVelocity(lastState.getVelocity());
            modelVec.set_dx_db(lastState.get_dx_db());
            modelData.push_back(modelVec);
            i++;
            h = 315570;
        }

        if((i < times.size()) && (times[i] - currentTime < h)){
            h = times[i] - currentTime;
        }
        
        currentTime += h;
    }

    return { result, modelData };
}

void Integrator::reset(){
    this->currentTime = 0;
}