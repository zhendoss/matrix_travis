#include "matrix.hpp"
#include "catch.hpp"

TEST_CASE("test matrix","[matrix]"){
    string A = "A.txt";
    Matrix matrix;
    matrix.Read(A);
    REQUIRE(matrix.Rows(A) == 3);
    REQUIRE(matrix.Columns(A) == 3);
    REQUIRE(3 == 3);
}
