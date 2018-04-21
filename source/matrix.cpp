#include <iostream>
#include "matrix.hpp"

using namespace std;

Matrix::Matrix(int row, int cols):  rows(row), columns(cols) {
    arr = new int *[row];
    for (int i = 0; i < row; i++) {
        arr[i] = new int[cols]{};
    }
}

Matrix::~Matrix() {
    for(int i = 0; i < rows; i++){
            delete[] arr[i];
        }
        delete[] arr;
}

int Matrix::Rows(string filename) {
    ifstream file(filename);
    int row;
    if (!file.is_open()){
        cout << "ERROR";
    }else{
        file >> row;
    }
    file.close();
    return row;
}

int Matrix::Columns(string filename) {
     ifstream file(filename);
    int row, column; 
    if (!file.is_open()){
        cout << "ERROR";
    }else{
        file >> row>>column;
    }
    file.close();
return column;
}

void Matrix::Read(string filename) {
    ifstream file(filename);
//
        if (!file.is_open()){
            cout << "ERROR";
        }else{
            file >> rows >> columns;

            arr = new int*[rows];
            for(int i = 0; i < rows; i++){
                arr[i] = new int[columns];
            }

            for(int i = 0; i < rows; i++){
                for(int j = 0; j < columns; j++){
                    file >> arr[i][j];
                }
            }
        }
        file.close();
}

void Matrix::Print() {
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            cout << arr[i][j] << " ";
        }
        cout<<endl;
    }
}
