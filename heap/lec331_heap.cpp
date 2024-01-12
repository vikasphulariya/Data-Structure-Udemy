#include<iostream>
#include<vector>
using namespace std;

void insert(vector<int> &heap,int val){
    if(heap.size()==0){
        cout<<"Heap is empty first create a heap"<<endl;
        return;
    }
    heap.push_back(val);
    int i=(heap.size()-1);
    int temp=val;
    while(i>0 && temp<heap[i/2]){
        heap[i]=heap[i/2];
        i=i/2;
    };
    heap[i]=temp;

}

int deleteFromHeap(vector<int> &heap){
    int ans=heap[0];
    if(heap.size()==1) {
    heap.pop_back();
        return ans;
    }
    int temp=heap[heap.size()-1];
    heap.pop_back();
    heap[0]=temp;
    int i=0,j=1; 
    while(j<(heap.size()-1)){
        if(heap[j+1]<heap[j]){
            j=j+1;
        }
        if(heap[i]>heap[j]){
            swap(heap[i],heap[j]);
            i=j;
            j=i*2;
        }
        else{
            break;
        }
    }
return ans;
}
void create(vector<int> &heap,int val){
if(heap.size()!=0){
        cout<<"Heap is already created "<<endl;
        return;
    };
    heap.push_back(val);
    cout<<"heap Created Sucessfully "<<endl;
    return;

}
void display(vector<int> heap){
    for(int i=0;i<heap.size();i++){
        cout<<heap[i]<<" ";
    }
}

int main(){
    vector<int> heap;
    create(heap,10);
    insert(heap,20);
    insert(heap,30);
    insert(heap,25);
    insert(heap,5);
    insert(heap,40);
    insert(heap,35);
    vector<int> sorted;
    int n=heap.size();
    for(int i=0;i<n;i++){
        sorted.push_back(deleteFromHeap(heap));
    }
    // deleteFromHeap(heap);
    // deleteFromHeap(heap);
    // deleteFromHeap(heap);
    // deleteFromHeap(heap);
    // deleteFromHeap(heap);
    // deleteFromHeap(heap);
    // deleteFromHeap(heap);
    display(sorted);
}