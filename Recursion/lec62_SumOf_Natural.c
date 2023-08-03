#include <stdio.h>


int fun(int n){
if(n>0){
    return fun(n-1)+n;
    // fun(n-1);
}
// printf("returning %d \n",n);
return 0;
}
int main(){
    int x=4 ;
    printf("%d\n",fun(x));
    // fun(x);
  }