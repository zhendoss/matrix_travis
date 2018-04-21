#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;
//списко инициализаторов

class Matrix{
private:
    int **arr;
    int rows;
    int columns;
public:
    Matrix(){}
    Matrix( matrix_t const & other );
    ~Matrix();
    
    Matrix & operator =( matrix_t const & other );

    int row() const;
    int column() const;

    istream & read( std::istream & stream );
    ostream & write( std::ostream & stream ) const;
};
