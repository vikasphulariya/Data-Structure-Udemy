#include<stdio.h>
int powerslow(int m,int n){
    if(n==0)
    {
        return 1;
    }
    if(n>0){
        return powerslow(m,n-1)*m;
    }
}

int powerFaster(int m,int n){
    if(n==0){
        return 1;
    }
    else if(n%2==0){
        return powerFaster(m*m,n/2);
    }      
    else{
        return m*powerFaster(m*m,(n-1)/2);
    }
}

int main(){
    int x=5;
    int y=2;
    printf("%d\n",powerslow(y,x)); 
    printf("%d\n",powerFaster(y,x)); 
}