#pragma once
#include <iostream>
#include <string>
#define random(y,x) y+rand()%(y-x+1)
using namespace std;
/*Zadanie1*/
template <typename T>
void fillDoubleArr(T** arr) {
    int size1 = _msize(arr) / sizeof(arr[0]);
    int size2 = _msize(arr[0]) / sizeof(arr[0][0]);
    for (int i = 0, k = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            arr[i][j] = 10 + k++;
        }
    }

}

template <typename T>
void showDoubleArr(T** arr) {
    int size1 = _msize(arr) / sizeof(arr[0]);
    for (int i = 0; i < size1; i++) {
        int size2 = _msize(arr[i]) / sizeof(arr[i][0]);
        for (int j = 0; j < size2; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

template<typename T>
void delStrokeInArr(T**& arr, int index) {
    int size1 = _msize(arr) / sizeof(arr[0]);
    int size2 = _msize(arr[0]) / sizeof(arr[0][0]);
    if (index >= size1 || index < 0) {
        cout << "Invalid index";
        return;
    }
    T** arr1 = new T * [size1 - 1];
    for (int i = 0; i < size1 - 1; i++) {
        arr1[i] = new T[size2];
    }
    for (int i = 0, k = 0; i < size1; i++) {
        if (index != i) arr1[k++] = arr[i];
    }
    delete[] arr[index];
    arr = arr1;

}

template <typename T>
void delColumnInArr(T**& arr, int index) {
    int size1 = _msize(arr) / sizeof(arr[0]);
    int size2 = _msize(arr[0]) / sizeof(arr[0][0]);
    if (index >= size2 || index < 0) {
        cout << "Invalid index" << endl;
        return;
    }
    T** arr1 = new T * [size1];
    for (int i = 0; i < size1; i++)
    {
        arr1[i] = new T[size2 - 1];
    }
    for (int i = 0; i < size1; i++) {
        for (int j = 0, k = 0; j < size2; j++) {
            if (j != index)
                arr1[i][k++] = arr[i][j];
        }
    }
    for (int i = 0; i < size1; i++)
    {
        delete[] arr[i];
    }
    delete[]arr;
    arr = arr1;
}

template <typename T>
int* findInDoubleArr(T** arr, int index) {
    int size1 = _msize(arr) / sizeof(arr[0]);
    int size2 = _msize(arr[0]) / sizeof(arr[0][0]);
    int* indexcollector = new int[2]{ -1,-1 };
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (arr[i][j] == index) {
                indexcollector[0] = i;
                indexcollector[1] = j;
                return indexcollector;
            }
        }
    }
    return indexcollector;

}

template <typename T>
void sortDoubleArr(T**& arr) {
    int size1 = _msize(arr) / sizeof(arr[0]);
    int size2 = _msize(arr[0]) / sizeof(arr[0][0]);
    bool flag = true;
    while (flag) {
        flag = false;
        for (int i = 0; i < size1; i++)
        {
            for (int j = 0; j < size2 - 1; j++)
            {
                if (arr[i][j] > arr[i][j + 1])
                {
                    swap(arr[i][j], arr[i][j + 1]);
                    flag = true;
                }
            }
        }
    }
}

template <typename T>
void swDArr(T** arr, T a, T b) {
    int size1 = _msize(arr) / sizeof(arr[0]);
    int size2 = _msize(arr[0]) / sizeof(arr[0][0]);
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (arr[i][j] == a)
                arr[i][j] = b;
        }
    }
}

