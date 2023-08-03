#include<iostream>
#include<stdio.h>
using namespace std;
struct rectangle {
    int length;
    int width;
};

int area(struct rectangle x){
    return(x.width*x.length);
}
int perimeter(struct rectangle x){
    return(2*(x.width   +x.length));
}
int main(){
    struct rectangle r={12,10};
    // r.width =10;
    // r.length =12;
    cout<<area(r)<<endl;
    cout<<perimeter(r)<<endl;

}