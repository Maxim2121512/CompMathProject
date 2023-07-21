#include "Date.h"

Date::Date(double year){
    this->year = this->startYear + year;
    convertYearToSeconds();
}

Date::Date(long long seconds){
    this->seconds = this->startSeconds + seconds;
    convertSecondsToYear();
}

long long Date::getSeconds(){
    return this->seconds;
}

double Date::getYear(){
    return this->year;
}

void Date::setSeconds(long long seconds){
    this->seconds = this->startSeconds + seconds;
    convertSecondsToYear();
}

void Date::setYear(double year){
    this->year = this->startYear + year;
    convertYearToSeconds();
}


void Date::convertSecondsToYear(){
    this->year = std::round(((double)this->seconds / (365.0 * 24.0 * 60.0 * 60.0)) * 1000) / 1000;
}

void Date::convertYearToSeconds(){
    this->seconds = this->year * (365 * 24 * 60 * 60);
}
