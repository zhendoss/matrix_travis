#include <iostream>
#include "matrix.hpp"

using namespace std;

Matrix::Matrix():rows(0), columns(0){}

Matrix::~Matrix(){}

int Matrix::row() const{return rows;}

int Matrix::column() const{return columns;}

istream & Matrix::read(istream & stream )
{
    char symbol;
    

    if( stream >> rows && stream >> symbol && symbol == ',' && stream >> columns ) {
        int ** a = new int *[ rows ];
        for( int i = 0;  i < rows; ++i ) {
            a[ i ] = new int[ columns ];
            for( int j = 0; j < columns; ++j ) {
                stream >> a[ i ][ j ];
	    }
	}
    }
	return stream;
}

ostream & Matrix::write(ostream & stream ) const
{
    stream << rows << ", " << columns;
    for( int i = 0; i < rows; ++i ) {
        stream << '\n';
        for( int j = 0; j < columns; ++j ) {
            stream << arr[ i ][ j ];
            if( j != rows - 1 ) {
                stream << ' ';
            }
        }
    }
    
	return stream;
}
