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

    int Rows(string filename);

    int Columns(string filename);



    void Read(string filename);

    void Print();
};
