#include<iostream>
using namespace std;

int main(){
    string k="afabaa";
    int j=k.size()-1;
    bool isPlaindrome=true;
    int i=0;
    while(i<j){
        if(k[i]!=k[j]){
            isPlaindrome=false;
            break;
        }
        i++;
        j--;
    }
    if(isPlaindrome){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}