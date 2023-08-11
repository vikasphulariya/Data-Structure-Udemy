#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
    int a[5];
    int b[5]={1,2,3,4,5};
    int n=sizeof(b)/sizeof(int);
    int c[5]={1,2,3};
    int d[5]={};
    cout<<n<<endl;
    int e[]={1,2,3,4};
    int i;
    for(i=0; i<5; i++){
        cout<<" a"<<a[i];
        cout<<" b"<<b[i];
        cout<<" c"<<c[i];
        cout<<" d"<<d[i];
        cout<<" e"<<e[i];
        cout<<endl;
    }
}