#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;
//списко инициализаторов

class Matrix{
private:
    int **arr;
    unsigned int rows;
    unsigned int columns;
public:
    Matrix(){}
    Matrix(int row, int cols);

    ~Matrix();

    int Rows();

    int Columns();



    void Read(string filename);

    void Print();
};
