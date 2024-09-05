#include <iostream>
#include <cstddef>

using namespace std;

class DoubleArray
{
    size_t d_size;
    double  *d_data;

     public:
        DoubleArray(size_t size = 1);

        double &operator[](size_t index);
};

DoubleArray::DoubleArray(size_t size)
:
    d_size(size),
    d_data(new double[d_size])
{}

double &DoubleArray::operator[](size_t index)
{
    return d_data[index];
}

class Matrix
{
    size_t d_nRows;
    size_t d_nCols;
    DoubleArray *d_row;

    public:
        Matrix(size_t nRows, size_t nCols);
        double &operator[](size_t row, size_t col);
        size_t nRows() const
        {
            return d_nRows;
        }
        size_t nCols() const
        {
            return d_nCols;
        }
};

Matrix::Matrix(size_t nRows, size_t nCols)
:
    d_nRows(nRows),
    d_nCols(nCols),
    d_row(new DoubleArray[nRows])
{}

double &Matrix::operator[](size_t row, size_t col)
{
    return d_row[row][col];
}

void init(Matrix &matrix, size_t value)
{
    for (size_t row = 0; row != matrix.nRows(); ++row)
        for (size_t col = 0; col != matrix.nCols(); ++col)
            matrix[row, col] = value++;
}

int main()
{
    Matrix matrix{ 2, 3 };
    init(matrix, 1);

    for (size_t row = 0; row != matrix.nRows(); ++row)
    {
        for (size_t col = 0; col != matrix.nCols(); ++col)
            cout << matrix[row, col] << ' ';
        cout.put('\n');
    }
}
