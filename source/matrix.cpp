#include <iostream>
#include "matrix.hpp"

using namespace std;

Matrix::Matrix() : arr{ nullptr }, rows{ 0 }, columns{ 0 }
{
}

Matrix::Matrix( Matrix const & other )
{
}

Matrix & Matrix::operator =( Matrix const & other )
{
	return *this;
}

Matrix::~Matrix()
{
}

int Matrix::row() const
{
    return rows;
}

int Matrix::column() const
{
    return columns;
}
