#include "Matrix.h"


Matrix::Matrix(int numRows, int numColumns){
    this->numRows = numRows;
    this->numColumns = numColumns;

    this->matrix.resize(numRows);
    for(int i = 0; i < matrix.size(); i++){
        matrix[i].resize(numColumns);
    }
}

Matrix::Matrix(int numRows, int numColumns, std::vector<std::vector<double>> matrix){
    this->numRows = numRows;
    this->numColumns = numColumns;
    this->matrix = matrix;
}

int Matrix::getNumRows() const{
    return this->numRows;
}

int Matrix::getNumColumns() const{
    return this->numColumns;
}

double Matrix::getElem(int row, int col) const{
    return this->matrix[row][col];
}

void Matrix::setElem(double value, int row, int col){
    this->matrix[row][col] = value;
}

Matrix Matrix::getIdentityMatrix() const{
    if(numRows != numColumns){
        std::cerr << "getIdentityMatrix(): num rows not equal num columns" << std::endl; 
    }

    Matrix identity(numRows, numColumns);

    for(int i = 0; i < numRows; i++){
        for(int j = 0; j < numColumns; j++){
            if(i == j){
                identity.matrix[i][j] = 1.0;
            }
        }
    }

    return identity;
}

Matrix Matrix::transpose() const{
    Matrix transposed(numColumns, numRows);

    for(int i = 0; i < numRows; i++){
        for(int j = 0; j < numColumns; j++){
            transposed.matrix[j][i] = this->matrix[i][j];
        }
    }

    return transposed;
}


Matrix Matrix::CholeskyDecomposition(Matrix other) const{
    if(other.numRows != other.numColumns){
        std::cerr << "CholeskyDecomposition(Matrix other): num rows not equal num columns" << std::endl; 
    }

    Matrix L(other.getNumRows(), other.getNumColumns());

    for(int i = 0; i < other.numRows; i++){
        for(int j = 0; j <= i; j++){
            long double sum = 0;

            for(int k = 0; k < j; k++){
                sum = std::fma(L.getElem(i,k), L.getElem(j, k), sum);
            }

            if( i == j ){
                long double temp = pow(10,79) * other.getElem(i,i) - pow(10,10) * sum;
                temp = temp / pow(10,79);
                L.setElem(sqrtl(temp), i, j);
            }
            else{
                L.setElem(( 1.0/ L.getElem(j,j) * (pow(10,79) * other.getElem(i,j) - sum * pow(10,79)))/pow(10,79), i, j);
            }
        }
    }

    return L;
}


Matrix operator+(Matrix const m1, Matrix const m2){
    if ((m1.numColumns != m2.numColumns) or (m1.numRows != m2.numRows)){
        std::cerr << "operarot+: numColumns or numRows not equal" << std::endl;
    }

    Matrix result(m1.numRows, m1.numColumns);

    for(int i = 0; i < result.numRows; i++){
        for(int j = 0; j < result.numColumns; j++){
            result.setElem(m1.getElem(i,j) + m2.getElem(i,j), i, j);
        }
    }

    return result;
}

Matrix operator-(Matrix const m1, Matrix const m2){
    if ((m1.numColumns != m2.numColumns) or (m1.numRows != m2.numRows)){
        std::cerr << "operarot-: numColumns or numRows not equal" << std::endl;
    }

    Matrix result(m1.numRows, m1.numColumns);

    for(int i = 0; i < result.numRows; i++){
        for(int j = 0; j < result.numColumns; j++){
            result.setElem(m1.getElem(i,j) - m2.getElem(i,j), i, j);
        }
    }
    
    return result;

}

Matrix operator*(Matrix const m1, double const vector[] )
    {
        Matrix result(m1.numRows, m1.numColumns);
        for (int i = 0; i < m1.numRows; i++)
        {
            for (int j = 0; j < m1.numColumns; j++)
            {
                result.setElem(m1.getElem(i, j) * vector[j], i, j);
            }
        }
        return result;
    }

Matrix operator*(Matrix const m1, Matrix const m2){
    if(m1.numColumns != m2.numRows){
        std::cerr << "operator*: left matrix num columns not equal right matrix num rows" << std::endl;
    }

    Matrix result(m1.numRows, m2.numColumns);

    for(int i = 0; i < result.numRows; i++){
        for(int j = 0; j < result.numColumns; j++){
            for(int k = 0; k < m2.numRows; k++){
                result.setElem(result.getElem(i,j) + (m1.getElem(i,k) * m2.getElem(k,j)), i, j);
            }
        }
    }

    return result;
}

Matrix operator*(double const scalar, Matrix const m1){
    Matrix result(m1.numRows, m1.numColumns);

    for(int i = 0; i < m1.numRows; i++){
        for(int j = 0; j < m1.numColumns; j++){
            result.setElem(m1.getElem(i,j) * scalar, i, j);
        }
    }

    return result;
}

std::ostream& operator<<(std::ostream& outStream, Matrix m){
    for(int i = 0; i < m.numRows; i++){
        for(int j = 0; j < m.numColumns; j++){
            outStream << m.getElem(i,j) << " ";
        }
        outStream << std::endl;
    }

    return outStream;
}