#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector<int> &A){
    int n = A.size();
    bool flag;
    for (int i=0;i < n;i++) {
        flag=true;
        for(int j=0;j<((n-1)-i);j++){
            if(A[j] > A[j+1]){
                // swap A[j] and A[j+1]
                int temp = A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
                flag=false;
            }
        }
        if(flag){
            break;
        }
    }
}

void display(vector<int> A){
    if(!A.size()){
        cout<<"Empty Array provided: "<<endl;
        return ;
    }
    for(int i=0;i<A.size();i++){
        cout << A[i] << " ";
    }
}

int main(){
    vector<int> k={1,2,34,5,46,2,4,5};
    cout<<"Before Sorting: \n";
    display(k);
    cout<<"After Sorting: \n";
    bubbleSort(k);
    display(k);
}