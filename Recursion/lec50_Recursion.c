#include <stdio.h>


void fun(int n){
if(n>0){
    printf("calling %d \n",n,",");
    fun(n-1);
}
printf("returning %d \n",n);
}
int main(){
    int x=3;
    fun(x);
  }