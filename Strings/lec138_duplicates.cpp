#include<iostream>
using namespace std;
int main(){
    char k[]="vikas is great";
    int a[25]={0};
    for(int i=0;k[i]!='\0';i++){
            a[(k[i]-'a')]++;
    }
    for(int i=0;i<25;i++){
        if(a[i]!=0){
            char c=i+'a';
            cout<<a[i]<<c<<endl;
        }
    }
}