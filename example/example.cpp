#include <iostream>
#include <fstream>
#include "matrix.hpp"
#include <cassert>
using namespace std;

int main() {

    string A = "/file/A.txt";
    string B = "/file/B.txt";
    string C = "/file/C.txt";
    string D = "/file/D.txt";

    Matrix matrix1;
    Matrix matrix2;
    Matrix matrix3;
    Matrix matrix4;
    Matrix matrix5;
    Matrix matrix6;
    Matrix matrix7;
    Matrix matrix8;
    Matrix matrix9;


    cout<<"Matrix A:"<<endl;
    matrix1.Read(A);
    matrix1.Print();

    cout<<"\nMatrix B:"<<endl;
    matrix2.Read(B);
    matrix2.Print();

    cout<<"\nMatrix A + Matrix B:"<<endl;
    matrix3 = matrix1 + matrix2;
    matrix3.Print();

    matrix8.Read(D);

    cout << "\nСравнимаем матрицы из файла D и матрицу - результат сложения матриц из файла A и B: " << (matrix3 == matrix8);

    cout<<"\n\nMatrix A - Matrix B:"<<endl;
    matrix4 = matrix1 - matrix2;
    matrix4.Print();

    cout<<"\nMatrix A * Matrix B:"<<endl;
    matrix5 = matrix1 * matrix2;
    matrix5.Print();

    cout<<"\nMatrix C:"<<endl;
    matrix6.Read(C);
    matrix6.Print();

    cout<<"\nMatrix C -> Transpont:"<<endl;
    matrix7 = matrix6.Transp();
    matrix7.Print();




    return 0;
}
