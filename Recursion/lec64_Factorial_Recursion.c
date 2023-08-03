#include <stdio.h>


int fact(int n){
if(n>0){
    return fact(n-1)*n;
    // fact(n-1);
}
// printf("returning %d \n",n);
return 1;
}
int main(){
    int x=3  ;
    printf("%d\n",fact(x));
    // fact(x);
  } 