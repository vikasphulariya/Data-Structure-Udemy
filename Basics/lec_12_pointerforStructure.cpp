#include<iostream>
#include<stdio.h>
#include<malloc.h>
using namespace std;

struct reactangle{
    int l;
    int b;
};
int main(){
    reactangle l={2,3};
    struct reactangle *p;
    struct reactangle *p1=(struct reactangle *)malloc(sizeof(struct reactangle));
    p=&l;
    p1->l=4;
    cout<<p1->l;
}