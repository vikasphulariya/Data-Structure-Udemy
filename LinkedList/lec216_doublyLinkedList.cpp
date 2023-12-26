#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;

}*first=NULL;

void create(int A[],int n){
    struct Node *t,*last;
    first=new Node;
    first->prev=NULL;
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++){
        // cout<<i<<" ";
        t=new Node;
        t->data=A[i];
        t->prev=last;
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void display(struct Node *p){
    struct Node *t=p;
    while (t!=NULL) {
        cout<<t->data<<" ";
        t=t->next;
    }
    cout<<endl;
}
int main(){
    int A[]={3,7,9,5};
    int n = sizeof(A)/sizeof(A[0]);
    create(A,n);
    display(first);
}