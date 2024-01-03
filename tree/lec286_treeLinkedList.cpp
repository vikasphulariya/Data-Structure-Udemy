#include <iostream>
using namespace std;
struct treeNode{
    struct treeNode *left;
    int data;
    struct treeNode *right;
};

struct Node
{
    struct treeNode *data;
    struct Node *next;
};
struct Queue
{
    struct Node *front = NULL;
    struct Node *last = NULL;
};



bool isEmpty(struct Queue *q){
    if (q->front == NULL)
    {
        return true;
    }
    return false;
};
void enqueue(struct Queue *&q, treeNode *data)
{
    struct Node *temp = new Node;
    temp->data = data; // assuming the user will enter a number for this field.
    temp->next = NULL;
    if (q->front == NULL)
    {
        q->front = temp;
        q->last = temp;
    }
    else
    {
      q->last->next=temp;
      q->last=temp;
    }
};
treeNode * dequeue(struct Queue *&q){
    struct treeNode* x=NULL;
    if(q->front==NULL){
        cout<<"Queue is empty"<<endl;
        return x;
    }
    if(q->front==q->last){
        // cout<<"eee"<<endl;
        x=q->front->data;
        q->front=NULL;
        q->last=NULL;
        return x;
    }
    struct Node* temp=q->front;
    x=q->front->data;
    q->front=q->front->next;
    return x;
};
void display(struct Queue *p){
    if(isEmpty(p)){
        cout << "The queue is Empty!" << endl;
        return;
    }
    struct Node *q=new Node;
    q=p->front;
    while(q){
        cout<<q->data<<" ";
        q=q->next;
    }
    cout<<endl;
};
struct treeNode *root=NULL;
void createTree(){
struct treeNode *p,*t;
int x;
struct Queue *q=new Queue;
cout<<"Enter root value:";
cin>>x;
root=new treeNode;
root->data=x;
root->left=root->right=NULL;
enqueue(q,root);

while(!isEmpty(q)){
    p=dequeue(q);
    cout<<"enter left child of "<<p->data<<" ";
    cin>>x;
    if(x!=-1){
        t=new treeNode;
        t->data=x;
        t->left=t->right=NULL;
        p->left=t;
        enqueue(q,t);
    }
    cout<<"enter right child "<<p->data<<" ";
    cin>>x;
    if(x!=-1){
        t=new treeNode;
        t->data=x;
        t->left=t->right=NULL;
        p->right=t;
        enqueue(q,t);
    }
}
// cout<<"ddd";
// display(q);

}
void preOrder(struct treeNode *root){
    if(root){
         cout<<root->data<<" "; 
         preOrder(root->left);
         preOrder(root->right);
    }
}
int main()
{
  createTree();
  preOrder(root);
}
