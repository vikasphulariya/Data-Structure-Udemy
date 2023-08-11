#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
int main()
{   
    int *c=(int*)malloc(sizeof(int)*5);
    int *a = new int[5];
    int i;
    // for C++
    for (i = 0; i < 5; i++)
    {
        a[i] = i + 1;
    }
    // for c
    for (i = 0; i < 5; i++)
    {
        c[i] = i + 1;
    }
    // for c++
    for (i = 0; i < 5; i++)
    {
        cout <<"c++ "<< a[i] << " " << endl;
    }
    // for c
    for (i = 0; i < 5; i++)
    {
        // cout << a[i] << " " << endl;
        printf("c %d\n",c[i]);
    }
    int *d=(int *)malloc(10*sizeof(int));//c
    int *b = new int[10];//c++
    // for c++
    for (i = 0; i < 5; i++)
    {
        b[i] = a[i];
    }
    delete[] a;
    a = b;
    b = NULL;
    //for c
    for (i = 0; i < 5; i++)
    {
        d[i] = c[i];
    }
    free(c);
    c= d;
    d = NULL;
    //for c++
    for(i=5; i < 10; i++){
        a[i] =i+1;
    }
    // for c
    for(i=5; i < 10; i++){
        c[i] =i+1;
    }
    // for c++
    for(i=0; i < 10; i++){
        cout<<"c++ "<<a[i]<<endl;
    }
    for(i=0; i < 10; i++){
        // cout<<a[i]<<endl;
        printf("c %d\n",c[i]);
    }
}