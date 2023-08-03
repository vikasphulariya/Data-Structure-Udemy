#include<iostream>
#include<stdio.h>
using namespace std;

template<class T>
class Airtmatic{
    private:
    T a;
    T b;
    public:
    Airtmatic(T a, T b);
    T add();
    T sub();
};

template<class T>
Airtmatic<T>::Airtmatic(T a, T b){
    this->a = a;
    this->b = b;
    cout<<"a: "<<a<<endl;
};

template<class T>
T Airtmatic<T>::add(){
    return(a+b);
};

template<class T> 
T Airtmatic<T>::sub(){
    return(b-a);
}

int main(){
Airtmatic<char> a(2,3);
cout<<a.add()<<endl;
cout<<a.sub()<<endl;
}

