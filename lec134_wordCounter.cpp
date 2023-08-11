#include<iostream>
using namespace std;
int main(){
    char s[]="hisdc cCD";
    int i;
    cout<<"Before Change Case: "<<s<<endl;
    int alphbets=0,vowels=0,words=0;
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
          vowels++;
        }
        if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
          vowels++;
        }
        if((s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122)){
          alphbets++;
        }
        if(s[i]==' ' && s[i-1]!=' '){
            words++;
        }
    }
    cout<<"Number of Vowels "<<vowels<<endl;
    cout<<"Number of alphbets "<<alphbets<<endl;
    cout<<"Number of words "<<words<<endl;
    return 0;
} 