#include <stdio.h>

double e(int x,int n){
    double s=1;
    int i=0;
    for(;n>0;n--){
        s=1+(s*x/n);
    }
    return s;
}

int main(){
    printf("%lf\n",e(3,30));  
}
