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

istream & Matrix::read( std::istream & stream )
{
    int r;
    int c;
    char symbol;
    
    bool success = true;
    if( stream >> r && stream >> symbol && symbol == ',' && stream >> c ) {
        int ** a = new int *[ r ];
        for( int i = 0; success && i < r; ++i ) {
            a[ i ] = new int[ c ];
            for( int j = 0; j < c; ++j ) {
                if( !( stream >> a[ i ][ j ] ) ) {
                    success = false;
                    break;
                }
            }
        }
        
        if( success ) {
            for( int i = 0; i < rows; ++i ) {
                delete [] arr[ i ];
            }
            delete [] arr;
            
            rows = r;
            columns = c;
            arr = a;
        }
        else {
            for( int i = 0; i < r; ++i ) {
                delete [] a[ i ];
            }
            delete [] a;
        }
    }
    else {
        success = false;
    }
    
    if( !success ) {
        stream.setstate(ios_base::failbit );
    }
    
	return stream;
}

ostream & Matrix::write(ostream & stream ) const
{
    stream << rows << ", " << collumns;
    for( int i = 0; i < rows; ++i ) {
        stream << '\n';
        for( int j = 0; j < collumns; ++j ) {
            stream << arr[ i ][ j ];
            if( j != rows - 1 ) {
                stream << ' ';
            }
        }
    }
    
	return stream;
}
