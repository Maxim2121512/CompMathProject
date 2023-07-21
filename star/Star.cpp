#include "Star.h"


StateVector Star::getInitialVector(){
    return this->initialVector;
}

StateVector Star::getLastStateFromHistory(){
    return this->history.back();
}

std::vector<ModelVector>& Star::getRealData(){
    return this->realData;
}

std::vector<ModelVector>& Star::getModelData(){
    return this->modelData;
}

std::vector<StateVector> Star::getHistory(){
    return this->history;
}

void Star::addStateToHistory(StateVector state){
    this->history.push_back(state);
}

void Star::setHistory(std::vector<StateVector> states){
    this->history = states;
}

void Star::addModelData(ModelVector data){
    this->modelData.push_back(data);
}

void Star::addRealData(ModelVector data){
    this->realData.push_back(data);
}

void Star::setModelData(std::vector<ModelVector> data){
    this->modelData = data;
}

void Star::setRealData(std::vector<ModelVector> data){
    this->realData = data;
}

void Star::setInitialState(StateVector newInitial){
    this->initialVector = newInitial;
}

void Star::clear(){
    this->history.clear();
    this->modelData.clear();
}