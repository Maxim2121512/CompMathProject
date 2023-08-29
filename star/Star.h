#pragma once

#include "../dataStructures/StateVector.h"
#include "../dataStructures/ModelVector.h"

class Star{
private:
    StateVector initialVector{-204165006081.4289, 41900659638.58861, -102471256234.72592, 11.52278359821609, 698.8066073842173, 360.98723429562403};
    std::vector<StateVector> history;
    std::vector<ModelVector> modelData;
    std::vector<ModelVector> realData;
public:
    Star() = default;
    StateVector getInitialVector();
    StateVector getLastStateFromHistory();
    std::vector<StateVector> getHistory();
    std::vector<ModelVector>& getModelData();
    std::vector<ModelVector>& getRealData();

    void addStateToHistory(StateVector state);
    void setHistory(std::vector<StateVector> states);
    void addModelData(ModelVector modelData);
    void addRealData(ModelVector realData);
    void setModelData(std::vector<ModelVector> modelData);
    void setRealData(std::vector<ModelVector> realData);
    void setInitialState(StateVector newState);
    void clear();
    ~Star() = default;
};







