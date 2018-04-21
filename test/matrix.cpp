#include "matrix.hpp"
#include "catch.hpp"

TEST_CASE("test matrix","[matrix]"){
    string A = "/file/A.txt";
    Matrix matrix;
    matrix.Read(A);
    REQUIRE(matrix.Rows() == 3);
    REQUIRE(matrix.Columns() == 3);
    REQUIRE(3 == 3);
}
