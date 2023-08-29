#pragma once
#include <math.h>

class Date{
private:
    double startYear = 2004.511;
    long long startSeconds = 2004.511 * 365 * 24 * 60 * 60; 
    double year = 0;
    long long seconds = 0;

    void convertYearToSeconds();
    void convertSecondsToYear();
public:
    Date() = default;
    Date(double year);
    Date(long long seconds);

    double getYear();
    long long getSeconds();

    void setYear(double year);
    void setSeconds(long long seconds);
};