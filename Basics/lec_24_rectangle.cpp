#include<iostream>
#include<stdio.h>
using namespace std;
int area(int x, int y){
    return(x*y);
}
int perimeter(int x, int y){
    return(2*(x+y));
}
int main(){
    int length=12;
    int width=10;
    cout<<area(length,width)<<endl;
    cout<<perimeter(length,width)<<endl;
}