#include<iostream>
#include<vector>

using namespace std;
void displayArray(vector<int> A){
    if(!A.size()){
        cout<<"The Array is Empty!"<<endl;
        return;
    }
    for(auto it : A){
        cout<<it<<" ";
    }
    cout<<endl;
}
void QuickSort(vector<int> &A,int l,int h){
 
    int pivot=A[l];
    int i=l,j=h;
    do{
        while(A[i]<=pivot){i++;}
       while(j>=l && A[j]>pivot) {j--;}
        if(i<j){
            swap(A[i],A[j]);
        }
    }while(i<j);
    swap(A[l],A[j]);
     if (l < j) {
        QuickSort(A, l, j);
    }
    if (j +1 < h) {
        QuickSort(A, j + 1, h);
    }
}

int main(){
    vector<int> k={23,32,22,42,46,232,67,12,45};
    cout<<"Original Array: \n";
    displayArray(k);
    cout<<"After Sorting: \n";
    QuickSort(k,0,k.size()-1);
    displayArray(k);

}