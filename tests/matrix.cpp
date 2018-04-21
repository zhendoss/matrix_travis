#include "matrix.hpp"
#include "catch.hpp"

TEST_CASE("creat"){
    Matrix matrix;
    REQUIRE(matrix.row() == 0);
    REQUIRE(matrix.column() == 0);
    
    Matrix matrix_1;
    REQUIRE(matrix_1.row() == 0);
    REQUIRE(matrix_1.column() == 0);
    
    Matrix matrix_2;
    REQUIRE(matrix_2.row() == 0);
    REQUIRE(matrix_2.column() == 0);
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
    
    string input_2{
        "3, 8\n"
        "1 2 3 4 5 6 7 8\n"
        "2 3 4 5 6 7 8 9\n"
        "3 4 5 6 7 8 9 10" };
    
    Matrix matrix;
    Matrix matrix_1;
    Matrix matrix_2;
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
    
    istringstream istream_2{ input_2 };
    REQUIRE( matrix_2.read( istream_2 ) );
    REQUIRE( matrix_2.row() == 3 );
    REQUIRE( matrix_2.column() == 8);
    
    ostringstream ostream_2;
    matrix_2.write( ostream_2 );
    
    REQUIRE( input_2 == ostream_2.str() );
    
}
