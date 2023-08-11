#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
int main(){
    int a[10];
    int *p;
    p=(int *)malloc(10*sizeof(int));
    for(int i=0; i<14; i++){
        p[i]=i;
    }
    for(int i=0; i<14; i++){
        cout<<p[i]<<endl;
    }
    int n=sizeof(p);
    cout<<n;
}