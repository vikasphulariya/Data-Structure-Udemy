#include<iostream>
#include<stdio.h>
#include<malloc.h>

using namespace std;
int add(int a,int b){
    return a + b;
}

void swap(int *a,int *b){
    // cout<<*a<<" "<<*b<<endl;
    int temp=*a;
    *a=*b;
    *b=temp;
}

void swapRefrence(int &x,int &y){
    int temp=x;
    x=y;
    y=temp;
}

//usess array pointer
void printArray(int B[],int n){
    for(int i=0;i<n;i++){
        cout<<B[i]<<endl;
        B[i]=B[i]+5;
    }
}

//use's int pointer
void printArrayBasic(int *B,int n){
    for(int i=0;i<n;i++){
        cout<<B[i]<<endl;

    }
}

int * createArray(int n){
    int *p;
    p=new int[n];
    for(int i=0;i<n;i++){
        p[i]=i;
    }

    return(p);
}
int main(){
    int A[5]={1,2,3,4,5};
    int a=6;
    int b=9;
    //lec 14
    // cout<<add(2,3)<<endl;

    //lec 16
    // swap(&a,&b);
    // cout<<a<<" "<<b<<endl;
    // swapRefrence(a,b);
    // cout<<a<<" "<<b<<endl;

    //lec 18
    // printArray(A,5);
    // cout<<"Refreshed Array"<<endl;
    // printArrayBasic(A,5);

    int *array;
    array=createArray(5);
    for(int i=0;i<5;i++){
        cout<<array[i]<<endl;
    }
}