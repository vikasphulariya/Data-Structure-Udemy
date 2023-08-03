#include <iostream>
#include<stdio.h>
using namespace std;
struct rectangle {
    int width;
    int length;
    char color;
};
int main(){

struct rectangle r={1,2};
printf("%d \n",sizeof(r));
cout<<r.width<<endl;
return 0;
}