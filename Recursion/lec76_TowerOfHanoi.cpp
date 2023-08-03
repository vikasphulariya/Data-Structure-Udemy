#include <stdio.h>
#include<iostream>
using namespace std;

void TOH(int n,int a,int b,int c){
    static int i = 0;
    if(n>0){
        TOH(n-1,a,c,b);
        i++;
        // cout<<i<<" FROM "<<a<<" to "<<c<<endl;
        printf("%d from %d to %d\n",i,a,c);
        TOH(n-1,b,a,c);   
    }
}
int main(){
    TOH(4,1,2,3);
    return 0;
}  