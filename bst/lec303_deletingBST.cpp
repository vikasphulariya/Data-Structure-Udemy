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


struct treeNode * createBST(struct treeNode *root,int data){
    if(root ==NULL){
        struct treeNode *temp = new treeNode;
        temp -> data = data;
        temp -> left = temp -> right = NULL;
        return temp;
    }
    else if(data==root->data){
        cout<<"element exist alreay";
        return NULL;
    }
    else if(data<root->data){
        root->left =createBST(root->left , data) ;
    }
    else{
        root->right=createBST(root->right,data);
    }
    return root;
}
void preOrder(struct treeNode *root){
    if(root){
         cout<<root->data<<" "; 
         preOrder(root->left);
         preOrder(root->right);
    }
}


int hieght(struct treeNode *p){
    if(p==NULL)return 0;
    int x,y;
    x=hieght(p->left);
    y=hieght(p->right);
    return x>y?x+1:y+1;
};

struct treeNode * inorderPre(struct treeNode *root){
    while(root && root->right!=NULL){
        root-root->right;
    }
    return root;
}
struct treeNode * inorderSuc(struct treeNode *root){
    while(root && root->left!=NULL){
        root-root->left;
    }
    return root;
}
struct treeNode * deleteBst(struct treeNode *root,int key){
    struct treeNode *q;
    if(root==NULL){
        cout<<" NULL "<<endl;
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){

        cout<<" NULL1 "<<endl;
        delete root;
        return NULL;
    }
    if(key<root->data){
        cout<<" NULL2 "<<endl;
        root->left=deleteBst(root->left,key);
    }
    else if(key>root->data){
        cout<<" NULL3 "<<endl;
        root->right=deleteBst(root->right,key);
    }
    else{
        cout<<" NULL4 "<<endl;
        if(hieght(root->left)>hieght(root->right)){
        cout<<" NULL5 "<<endl;
            q=inorderPre(root->left);
            root->data=q->data;
            root->left=deleteBst(root->left,q->data);
        }
        else{
        cout<<" NULL6 "<<endl;
            q=inorderPre(root->right);
            root->data=q->data;
            root->left=deleteBst(root->left,q->data);
        }
    }
    return root;
}
int main()
{
    struct treeNode *root=NULL;
  root=createBST(root,5);
  root=createBST(root,7);
  root=createBST(root,9);
  root=createBST(root,91);
  root=createBST(root,13);
  root=deleteBst(root,9);
  preOrder(root);

}
