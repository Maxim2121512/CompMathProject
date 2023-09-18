#pragma once

#include "../dataStructures/StateVector.h"
#include "../dataStructures/ModelVector.h"

class Star{
private:
    StateVector initialVector{-533305124.556169391, 442612871.052988231, -157666045721.682739, 1097.36424, -968.220292, -552.823312};
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







