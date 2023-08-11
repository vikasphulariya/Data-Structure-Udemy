#include<iostream>
using namespace std;
int main(){
    char s[]="hisdc cCD";
    int i;
    cout<<"Before Change Case: "<<s<<endl;
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]>=65 && s[i]<=90){
            s[i]=s[i]+32;
            continue;
        }
        if(s[i]>=97 && s[i]<=122){
            s[i]=s[i]-32;
            continue;
        }
    }
    cout<<"After Case Change: "<<s<<endl;
    return 0;
} 