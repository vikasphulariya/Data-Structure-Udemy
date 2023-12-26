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
int count(struct Node *p)
{
    int c = 0;
    while (p)
    {
        c++;
        p = p->next;
    }
    return c;
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

void display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    cout<<endl;
}

void insert(struct Node *p, int data,int pos){
    if(pos<0 || pos>count(p)){
        cout<<"Insertion fiailed "<<count(p)<<endl;
        return ;
    }
    struct Node *t= new Node;
    // cout<<"Fvfdv";
    t->data=data;
    if(pos==0){
        t->next=first;
        first=t;
    }
    else{
        for(int i=0;i<(pos-1)&&p;i++){
         p=p->next;   
        }
        t->next=p->next;
        p->next=t;
    }
        cout<<"inserted"<<endl;
}   

void deleteDuplicate(struct Node *p){
    // struct Node* temp = p;
    struct Node* next = p -> next;
    while(next){

    if(next->data!=p->data && next){
        p=next;
        next=next->next;
    }
    else{
        p->next=next->next;
        delete next;
        next=p->next;
    }
    }
}
int main(){
    int A[]={1,1,1,1,1,2,3,5,5,5,5,5,6,6,6,6,6};
    int n=sizeof(A)/sizeof(A[0]);
    create(A,n);
    // Search(first,12);s
    display(first);
    // display(first);
    // cout<<"After insertion"<<endl;
    // insert(first,22,0);
    deleteDuplicate(first);
    display(first);
}