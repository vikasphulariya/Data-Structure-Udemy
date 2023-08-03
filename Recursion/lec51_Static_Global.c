#include <stdio.h>


int fun(int n){
    static int x=0;
if(n>0){
    // printf("calling %d \n",n,",");
    x++;
    return fun(n-1)+x;
}
// printf("returning %d \n",n);
return 0;
}
int main(){
    int x= 5;
    printf("%d ",fun(x));
    printf("%d ",fun(x));
   }