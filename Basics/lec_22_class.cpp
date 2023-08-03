#include<iostream>
#include<stdio.h>
using namespace std;
class reactangle {
private:
    int l;
    int w;
    public:
reactangle(int l, int w){

    this->l = l;
    this->w = w;
}

void ChangeValue(int l,int w){
     this->l = l;
    this->w = w;
}
void areaOfReactangle(){
    cout<<"Area of Reactangle: "<<(w*l)<<endl;
}

};
int main(){
    reactangle r(2,3);
    // intialize(&r,2,3);
    r.areaOfReactangle();
    r.ChangeValue(3,5);
    r.areaOfReactangle();
    // cout<<"Area of Reactangle: "<<(r.w)<<endl;
}