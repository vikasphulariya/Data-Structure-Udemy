#include <iostream>
using namespace std;
struct Node
{
    int data;
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
void enqueue(struct Queue *&q, int data)
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
void dequeue(struct Queue *&q){
    if(q->front==NULL){
        cout<<"Queue is empty"<<endl;
        return;
    }
    if(q->front==q->last){
        cout<<"eee"<<endl;
        cout<<q->front->data<<endl;
        q->front=NULL;
        q->last=NULL;
        return;
    }
    struct Node* temp=q->front;
        cout<<q->front->data<<endl;
    q->front=q->front->next;
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
int main()
{
    struct Queue *q = new Queue;
    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    display(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    cout << "Hello World" << endl;
}
