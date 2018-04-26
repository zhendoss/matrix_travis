#include "catch.hpp"
#include "matrix.hpp"
SCENARIO("matrix new w/o params","[new w/o params]"){
    Matrix matrix;
    REQUIRE(matrix.Rows() == 0);
    REQUIRE(matrix.Columns() == 0);
}

SCENARIO("matrix new with params","[new with params]"){
    Matrix matrix(3,3);
    REQUIRE(matrix.Rows() == 3);
    REQUIRE(matrix.Columns() == 3);
}

SCENARIO("matrix operator+","[oper+]"){
    Matrix matrix1(2,2), matrix2(2,2);
    ofstream file1("A.txt");
    file1 << "1 2 3 4";
    file1.close();
    ofstream file2("B.txt");
    file2 << "5 6 7 8";
    file2.close();
    matrix1.Read("A.txt");
    matrix2.Read("B.txt");
    REQUIRE(matrix1.Element(0,0) + matrix2.Element(0,0) == 6);
    REQUIRE(matrix1.Element(0,1) + matrix2.Element(0,1) == 8);
    REQUIRE(matrix1.Element(1,0) + matrix2.Element(1,0) == 10);
    REQUIRE(matrix1.Element(1,1) + matrix2.Element(1,1) == 12);
}

SCENARIO("matrix operator-","[oper-]"){
    Matrix matrix1(2,2), matrix2(2,2);
    ofstream file1("A.txt");
    file1 << "1 2 3 4";
    file1.close();
    ofstream file2("B.txt");
    file2 << "4 6 8 1";
    file2.close();
    matrix1.Read("A.txt");
    matrix2.Read("B.txt");
    REQUIRE(matrix2.Element(0,0) - matrix1.Element(0,0) == 3);
    REQUIRE(matrix2.Element(0,1) - matrix1.Element(0,1) == 4);
    REQUIRE(matrix2.Element(1,0) - matrix1.Element(1,0) == 5);
    REQUIRE(matrix2.Element(1,1) - matrix1.Element(1,1) == -3);
}

SCENARIO("matrix operator*", "[oper*]") {
    Matrix matrix1(2,2), matrix2(2,2);
    ofstream file1("A.txt");
    file1 << "1 2 3 4";
    file1.close();
    ofstream file2("B.txt");
    file2 << "4 3 2 1";
    file2.close();
    matrix1.Read("A.txt");
    matrix2.Read("B.txt");
    REQUIRE(matrix1.Element(0,0) * matrix2.Element(0,0) + matrix1.Element(0,1) * matrix2.Element(1,0) == 8);
    REQUIRE(matrix1.Element(0,0) * matrix2.Element(0,1) + matrix1.Element(0,1) * matrix2.Element(1,1) == 5);
    REQUIRE(matrix1.Element(1,0) * matrix2.Element(0,0) + matrix1.Element(1,1) * matrix2.Element(1,0) == 20);
    REQUIRE(matrix1.Element(1,0) * matrix2.Element(0,1) + matrix1.Element(1,1) * matrix2.Element(1,1) == 13);
}

SCENARIO("matrix operator==" , "[oper==]") {
    Matrix matrix1(2,2), matrix2(2,2);
    ofstream file1("A.txt");
    file1 << "1 1 1 1";
    file1.close();
    ofstream file2("B.txt");
    file2 << "1 1 1 1";
    file2.close();
    matrix1.Read("A.txt");
    matrix2.Read("B.txt");
    for (int i = 0; i < matrix1.Rows(); i++)
    {
        for (int j = 0; j < matrix1.Columns(); j++)
        {
            REQUIRE(matrix1.Element(i,j) == matrix2.Element(i,j));
        }
    }

}

SCENARIO("matrix operator=" , "[oper=]") {
    Matrix matrix1(2,2), matrix2(2,2);
    ofstream file1("A.txt");
    file1 << "1 2 3 4";
    file1.close();
    matrix1.Read("A.txt");
    matrix2 = matrix1;
    REQUIRE(matrix1.Element(0,0) == 1);
    REQUIRE(matrix1.Element(0,1) == 2);
    REQUIRE(matrix1.Element(1,0) == 3);
    REQUIRE(matrix1.Element(1,1) == 4);

}
