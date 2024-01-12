#include<iostream>
using namespace std;


int linearsearch( int num , int arr[] ){
    int count = 0 ; 
    
    for ( int i =0 ; i< num ; i++){
       if( arr[i]==num ){
        count++;
       }
    }
    return count;
}


int main(){

    cout<<"Enter the number you ant to find"<<endl;
    int num ; 
    cin>>num; 
    int arr[10]={1,3,2,5,4,6,2,4,3,10};

   int result= linearsearch(num , arr );
   cout<<num<<"appears "<<result<<" tymes in the given array"<<endl;
   return 0;
}