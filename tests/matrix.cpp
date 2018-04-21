#include "matrix.hpp"
#include "catch.hpp"

TEST_CASE("creat"){
    Matrix matrix;
    REQUIRE(matrix.row() == 0);
    REQUIRE(matrix.column() == 0);
}

TEST_CASE("read"){
    std::string input{
        "3, 3\n"
        "1 1 1\n"
        "2 2 2\n"
        "3 3 3" };
    Matrix matrix;
    istringstream istream{ input };
    
    REQUIRE( matrix.read( istream ) );
    REQUIRE( matrix.row() == 3 );
    REQUIRE( matrix.column() == 3 );
    
    ostringstream ostream;
    matrix.write( ostream );
    
    REQUIRE( input == ostream.str() );
}
