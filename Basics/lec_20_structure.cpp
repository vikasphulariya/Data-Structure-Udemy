#include<iostream>
#include<stdio.h>
using namespace std;
struct rectangle{
    int width;
    int length;
};
//call by pointer
int areaByP(struct rectangle *a){
    
    a->width = 3;
    return(a->width*a->length);
}
//call by value
int areaByV(struct rectangle a){
    // a.width = 3;
    return(a.width*a.length);
}
//call by reference
int areaByR(struct rectangle &a){
    return(a.width*a.length);
}\

struct temp{
    int a[5];
    int l;
};

void printTemp(int *a,int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }
}

//To create a struct using function
struct rectangle createRect(int len,int wid){
    struct rectangle *p;
    // p=(struct rectangle *)malloc(sizeof(struct rectangle));
    p=new rectangle;
    // cout<<wid<<endl;
    p->width=wid;
    p->length=len;
    return(*p);
}
int main(){
    // struct rectangle r;
    // r.width=2;
    // r.length=3;
    // cout<<"length: "<<r.length<<endl;
    // cout<<"width: "<<r.width<<endl;
    // cout<<"call by Value "<<areaByV(r)<<endl;
    // cout<<"call by Pointer "<<areaByP(&r)<<endl;
    // cout<<"call by Refrence "<<areaByR(r)<<endl;
    // cout<<"length: "<<r.length<<endl;
    // cout<<"width: "<<r.width<<endl;

    // struct temp t;
    // t.a={1,2,3,4,5};
    // t.l=3;
    // printTemp(t.a,5);
    struct rectangle r;
    r=createRect(10,15);
    cout<<"width: "<<r.width<<endl;
    cout<<"length: "<<r.length<<endl;
}