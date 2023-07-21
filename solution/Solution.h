#pragma once

#include "../star/Star.h"
#include "../GaussNewton/GaussNewton.h"
#include "../integrator/Integrator.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>

class Solution{
private:
    Star s55;
    Integrator integrator;
    GaussNewton gaussNewton;
public:
    Solution() = default;

    void directProblem();
    void inverseProblem();
    void writeDirectProblemResult();
    void readObservatoryData();
    void generalSolution();
    void clear();
    ~Solution() = default;
};