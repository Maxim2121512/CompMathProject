#pragma once

#include "../dataStructures/StateVector.h"
#include "../Constants.h"
#include "../dataStructures/ModelVector.h"
#include <iomanip>
#include <algorithm>

class Integrator{
private:
    std::vector<double> times = {2004.511, 2004.516, 2005.268, 2006.490, 2006.584, 2006.726, 2006.800, 2007.205, 2007.255, 2007.455, 
    2008.145, 2008.197, 2008.268, 2008.456, 2008.598, 2008.708, 2009.334, 2009.501, 2009.605, 2009.715, 2010.444, 2010.455, 2011.400, 2012.374, 2013.488, 2015.581};
    int currentTime = 0;
    int h = 31536; // step - 0.001 year
    int endTime = 13.1 * 365 * 24 * 60 * 60; 
public:
    Integrator() = default;

    StateVector rsFunction(StateVector vector);
    void calculatePartialDerivates(StateVector& state, Matrix& partialDerivates);
    std::pair<std::vector<StateVector>, std::vector<ModelVector>> RK4(StateVector initialState);

    void reset();
    ~Integrator() = default;
};