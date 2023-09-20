#pragma once

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>

class Matrix{
private:

    int numRows = 0;
    int numColumns = 0;
    std::vector<std::vector<double>> matrix;

public:
    Matrix(int numRows, int numColumns);
    Matrix(int numRows, int numColumns, std::vector<std::vector<double>> matrix);

    int getNumRows() const;
    int getNumColumns() const;
    double getElem(int row, int col) const;

    void setElem(double value, int row, int col);
    Matrix getIdentityMatrix() const;
    Matrix transpose() const;
    Matrix CholeskyDecomposition(Matrix other) const;


    friend Matrix operator+(Matrix const m1, Matrix const m2);
    friend Matrix operator-(Matrix const m1, Matrix const m2);
    friend Matrix operator*(Matrix const m1, Matrix const m2);
    friend Matrix operator*(Matrix const A, double const vector[]);
    friend Matrix operator*(double const scalar, Matrix const m);
    friend std::ostream& operator<<(std::ostream& outStream, Matrix m);
    ~Matrix() = default;
};