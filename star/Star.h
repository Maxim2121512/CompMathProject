#pragma once

#include "../dataStructures/StateVector.h"
#include "../dataStructures/ModelVector.h"

class Star{
private:
    StateVector initialVector{202489678119.6209, 31064725685.65855, 106945561101.91441, 123.58397725118365, 724.4824277946129, 292.13705085720505};
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







