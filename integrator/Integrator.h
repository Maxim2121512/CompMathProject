#pragma once

#include "../dataStructures/StateVector.h"
#include "../Constants.h"
#include "../dataStructures/ModelVector.h"
#include <iomanip>
#include <algorithm>

class Integrator{
private:
    std::vector<int> times = {0, 157680, 23872752, 62409744, 65374128, 69852240, 72185904, 84957984, 86534784, 92841984, 114601824, 116241696, 118480752,
    124409520, 128887632, 132356592, 152098128, 157364640, 160644384, 164113344, 187103088, 187449984, 217251504, 247967568, 283098672, 349103520};
    int currentTime = 0;
    int h = 315570;
    int endTime = 449103521;
public:
    Integrator() = default;

    StateVector rsFunction(StateVector vector);
    void calculatePartialDerivates(StateVector& state, Matrix& partialDerivates);
    std::pair<std::vector<StateVector>, std::vector<ModelVector>> RK4(StateVector initialState);

    void reset();
    ~Integrator() = default;
};