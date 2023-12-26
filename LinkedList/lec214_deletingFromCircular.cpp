#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *head = NULL;

void Create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    head = new Node;
    // head = t;
    head->data = A[0];
    head->next = head;
    // cout<<"rr";
    last = head;

    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void display(struct Node *f)
{
    // cout<<"dd";
    struct Node *t = f;
    do
    {

        cout << t->data << " ";
        t = t->next;

    } while (t != f);
}

void Rdisplay(struct Node *h)
{
    static int flag = 0;
    if (h != head || flag == 0)
    {
        flag = 1;
        cout << h->data << " ";
        Rdisplay(h->next);
    }
    flag = 0;
}

void deletek(struct Node *H,int pos){
    struct Node *p=H;
    if(pos==0){
        while(p->next!=head){
            p=p->next;
        }
        p->next=head->next;
        cout<<"Deleted "<<head->data<<endl;
        delete head;
        head=p->next;
    }
    else{
        for(int i=0;i<pos-1;i++){
            p=p->next;
        }
        struct Node *q=p->next;
        p->next=q->next;
        cout<<"deleted "<<q->data<<endl;
        delete q;
    }
}

int main()
{
    int A[] = {1, 22, 3, 4, 5};
    Create(A, 5);
    deletek(head,1);
    display(head);
}
