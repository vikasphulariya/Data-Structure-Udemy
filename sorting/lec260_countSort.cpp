#include<iostream>
#include<vector>
#include<map>
using namespace std;

void createMap(map<int,int> &Map,vector<int> A){
    for (int i = 0;i < A.size();++i) {
        Map[A[i]]++;
    }
}

void displayMap(map<int,int> M){
    for(auto i:M){
        cout<<i.first<<" "<<i.second;
        cout<<endl;
    }
}

void countSort(vector<int> &A){
    map<int,int> M;
    //create the frequency map of elements in array
    createMap(M,A);
    // displayMap(M);;
    int j=0;
    for(auto i:M){
        while(i.second){
            A[j++] = i.first;
            i.second--;
            // cout<<"inserted "<<i.first<<endl;
        }
    }
}

void displayArray(vector<int> A){
    for(auto x : A){
    cout<<x<<" ";
    }
    cout<<endl;
}


int main(){
    vector<int> V={12,34,56,78,9,2,5,7,2,5,2,12,32,5,71};
    cout<<"Origanl Array :";
    displayArray(V);
    countSort(V);
    cout<<"After Sorting Arrat: ";
    displayArray(V);
}