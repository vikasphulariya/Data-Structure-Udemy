#include<iostream>
#include<stdio.h>
using namespace std;
struct reactangle {
    int l;
    int w;
};
void intialize(struct reactangle *a,int l, int w){

    a->l = l;
    a->w = w;
}

void areaOfReactangle(struct reactangle a){
    cout<<"Area of Reactangle: "<<(a.w*a.l)<<endl;
}

void ChangeValue(struct reactangle *a,int l,int w){
     a->l = l;
    a->w = w;
}
int main(){
    struct reactangle r;
    intialize(&r,2,3);
    areaOfReactangle(r);
    ChangeValue(&r,3,5);
    areaOfReactangle(r);
    cout<<"Area of Reactangle: "<<(r.w)<<endl;
}