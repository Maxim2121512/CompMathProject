#pragma once

#include "../dataStructures/StateVector.h"
#include "../dataStructures/ModelVector.h"

class Star{
private:
    StateVector initialVector{-200366644535.43903,
45170910407.46076,
-98507268323.3332,
64.7641404708107,
690.2970674513934,
389.27496200388297};
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







