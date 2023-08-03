#include <stdio.h>
int loopF(int n){
    if(n<=1) return n;
    int s=0,t0=0,t1=1;
    int i=2;
    for (i;i<=n;i++){
        s=t0+t1;
        t0=t1 ;
        t1=s;
    }
    return s;
}

int rF(int n){
    if(n<=1) return n;
    return rF(n-2)+rF(n-1);
}

// int 

int main(){
    printf("%d\n",loopF(10000));
    printf("%d\n",rF(10));
}