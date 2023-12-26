#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

void create(int A[], int n)
{

    int i;
    struct Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void create2(int A[], int n)
{

    int i;
    struct Node *t, *last;
    second = new Node;
    second->data = A[0];
    second->next = NULL;
    last = second;
    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p)
{
    while (p != NULL)
    {
        cout << (p->data) << " ";
        p = p->next;
    }
    cout << endl;
}

void merge()
{
    cout<<endl;
    struct Node *last = NULL;
    third = new Node;
    third = NULL;
    while (first != NULL && second != NULL)
    {
        cout<<first->data<<" "<<second->data;
        if (first->data < second->data)
        {
            cout<<" first ";
            if (third == NULL)
            {
                cout<<" 1 "<<endl;
                third = first;
                last = first;
                first = first->next;
                last->next = NULL;
            }
            else
            {
                cout<<" 2 "<<endl;
                last->next = first;
                last = first;
                first = first->next;
                last->next = NULL;
            }
        }
        else
        {
            cout<<" Second ";
            if (third == NULL)
            {
                cout<<" 1 "<<endl;
                third = second;
                last = second;
                second = second->next;
                last->next = NULL;
            }
            else
            {
                cout<<" 2 "<<endl;
                last->next = second;
                last = second;
                second = second->next;
                last->next = NULL;
            }
        }
    }
    cout << "Merge SuccesFull" << endl;
}
bool sorted(struct Node *p)
{
    int min = p->data;
    // p = p->next;
    while (p)
    {
        // cout<<min<<" > "<<(p->data)<<endl;
        if (min > p->data)
        {
            // cout << "sf";
            return false;
        }
        min = p->data;
        p = p->next;
    }
    return true;
}
bool isLoop(struct Node *f){
    cout<<"isloop";
    struct Node *p=f,*q=f;
    do{
        p=p->next;
        q=q->next;
        q=q?q->next:q;
        // cout<<"ccc "<<p<<" "<<q<<endl;
        
    }while(p && q && p!=q );
    if(p==q){
        return true;
    }
    return false;
}


int main()
{

    struct Node *t1,*t2;
    int A[] = {1,  13, 14,21, 56, 76};
    int B[] = { 5,10, 22, 34, 45, 66};

    create(A, 6);
    t1=first->next->next;
    t2=first->next->next->next->next->next;
    // cout<<t2->data;
    t2->next=t1;
    // merge();
    // display(first);
    cout<<isLoop(first);
    return 0;
}
