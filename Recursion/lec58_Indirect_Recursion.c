#include <stdio.h>


void fun1(int n){
if(n>0){
    printf("calling %d \n",n,",");
    fun2(n-1);
}
}
void fun2(int n){
if(n>0){
    printf("calling %d \n",n,",");
    fun1(n/2);
}
// printf("returning %d \n",n);
}
int main(){
    int x=20;
    fun1(x);
  }