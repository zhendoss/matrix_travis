#include "matrix.hpp"
#include "catch.hpp"

TEST_CASE("creat"){
    Matrix matrix;
    REQUIRE(matrix.row() == 0);
    REQUIRE(matrix.column() == 0);
    
}

TEST_CASE("read"){
    string input{
        "3, 3\n"
        "1 1 1\n"
        "2 2 2\n"
        "3 3 3" };
    
    string input_1{
        "1, 1\n"
        "1" };
       
    Matrix matrix;
    Matrix matrix_1;
    istringstream istream{ input };
    
    REQUIRE( matrix.read( istream ) );
    REQUIRE( matrix.row() == 3 );
    REQUIRE( matrix.column() == 3 );
    
    ostringstream ostream;
    matrix.write( ostream );
    
    REQUIRE( input == ostream.str() );
    
    istringstream istream_1{ input_1 };
    REQUIRE( matrix_1.read( istream_1 ) );
    REQUIRE( matrix_1.row() == 1 );
    REQUIRE( matrix_1.column() == 1);
    
    ostringstream ostream_1;
    matrix_1.write( ostream_1 );
    
    REQUIRE( input_1 == ostream_1.str() );    
}
