#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*first=NULL;
void create(int A[],int n){
    struct Node *t,*last;
    first=new Node;
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++){
        t=new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;

    }
}

void Search(struct Node *p,int key)
{
    while(p){
        if(key==p->data){
            cout<<"Element found at address: " << p ;
            return ;
        }
        p=p->next;
    }
    cout<<"Element not FOund";
}
int main(){
    int A[]={1,2,3,45,6};
    int n=sizeof(A)/sizeof(A[0]);
    create(A,n);
    Search(first,12);

}