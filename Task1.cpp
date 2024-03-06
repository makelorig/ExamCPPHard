#include "Task1.h"


int main()
{
    srand(time(NULL));

    const int SIZW = 18;
    int** dbmass = new int* [SIZW];
    for (int i = 0; i < SIZW; i++)
    {
        dbmass[i] = new int[5];
    }
    fillDoubleArr(dbmass);
    showDoubleArr(dbmass);
    cout << endl;

    delStrokeInArr(dbmass,3);
    showDoubleArr(dbmass);
    cout << endl;

    delColumnInArr(dbmass, 2);
    showDoubleArr(dbmass);
    cout << endl;

    int* c= findInDoubleArr(dbmass, 34);
    cout << c[0] <<" " << c[1] << endl << endl;

    sortDoubleArr(dbmass);
    showDoubleArr(dbmass);
    cout << endl;

    swDArr(dbmass, 52, 78);
    showDoubleArr(dbmass);
    return 0;
    
}

