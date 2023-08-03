#include<iostream>
using namespace std;
int main(){
    int a=10;
    int &r=a;
    r=r+1;
    cout<<r<<endl;
    cout<<a;
}