#include <stdio.h>
#include <string.h>
#include <conio.h>
void reverseString(char* s, int sSize){
    static int i=0;
    if(i<=sSize){
        // printf("%c",s[sSize]);
        // s[sSize] = 'd';
         char ch = s[i];
            s[i] = s[sSize-1];
            s[sSize-1] = ch;
            i++;
        reverseString(s,sSize-1);
    }
    else{
        //   printf("%c",s[sSize-1]);
           
        // printf("%c",s[sSize-1]);
    }
}

int main(){

    char s[] = "hello";
    reverseString(s,5);
    // printf("%c",s[1]);
    printf("\n%s",s);

}