#include <stdio.h>

int x1 = 0;
int fun(int n){
    x1++;
if(n>100){
    printf("calling %d \n",n);
    // printf("%d ",x1);
    return(n-10);
}
else{
    return fun(fun(n+11));
}
// printf("returning %d \n",n);
}
int main(){
    int x=30;
    printf("%d \n",fun(x));
    printf("%d",x1);

  }