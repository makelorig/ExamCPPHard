#pragma once
#include <iostream>
#include <string>
#define random(y,x) y+rand()%(y-x+1)
using namespace std;
/*Zadanie1*/
template <typename T>
void fillDoubleArr(T** arr);

template <typename T>
void showDoubleArr(T** arr);
/*Zadanie2*/
template<typename T>
void delStrokeInArr(T** &arr, int index);
/*Zadanie3*/
template <typename T>
void delColumnInArr(T**& arr, int index);
/*Zadanie4*/
template <typename T>
int* findInDoubleArr(T** arr, int index);
/*Zadanie5*/
template <typename T>
void sortDoubleArr(T**& arr);
/*Zadanie6*/
template <typename T>
void swDArr(T** arr, T a, T b);
