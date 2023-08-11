#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main()
{
    // Stack Only
    int a[3][4];
    int i;
    int k;
    int j;
    j = 0;
    cout << "Stack only" << endl;
    for (i = 0; i < 3; i++)
    {
        for (k = 0; k < 4; k++)
        {
            j++;
            a[i][k] = j;
        }
    }
    for (i = 0; i < 3; i++)
    {
        j++;
        for (k = 0; k < 4; k++)
        {
            cout << a[i][k] << " ";
        }
        cout << endl;
    }
    // stack+heap
    cout << "Stack+heap" << endl;
    j = 0;
    int *A[3];
    for (i = 0; i < 3; i++)
    {
        A[i] = new int[4];
    }
    for (i = 0; i < 3; i++)
    {
        for (k = 0; k < 4; k++)
        {
            j++;
            A[i][k] = j;
        }
    }
    for (i = 0; i < 3; i++)
    {
        j++;
        for (k = 0; k < 4; k++)
        {
            cout << A[i][k] << " ";
        }
        cout << endl;
    }
    // heap Only
    cout << "heap only" << endl;
    j = 0;
    int **B;
    B = new int *[3];
    for (i = 0; i < 3; i++)
    {
        B[i] = new int[4];
    } 
    for (i = 0; i < 3; i++)
    {
        for (k = 0; k < 4; k++)
        {
            j++;
            B[i][k] = j;
        }
    }
    for (i = 0; i < 3; i++)
    {
        j++;
        for (k = 0; k < 4; k++)
        {
            cout << a[i][k] << " ";
        }
        cout << endl;
    }
}