#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;

} *first = NULL;

void create(int A[], int n)
{
    struct Node *t, *last;
    first = new Node;
    first->prev = NULL;
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        // cout<<i<<" ";
        t = new Node;
        t->data = A[i];
        t->prev = last;
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p)
{
    struct Node *t = p;
    struct Node *q;
    while (t != NULL)
    {
        if (t->next == NULL)
        {
            // cout << "Dd";
            q = t;
        }
        cout << t->data  << " ";
        t = t->next;
    }
    cout << "Now Reversing \n";
    while (q)
    {   

        cout << q->data << " ";
        q = q->prev;
    }
    cout << endl;
}
void insert(struct Node *p, int data, int pos)
{
    struct Node *t = new Node;
    t->data = data;
    if (pos == 0)
    {
        t->next = first;
        first->prev = t;
        t->prev = NULL;
        first = t;
    }
    else
    {
        for (int i = 0; i < pos - 1 && p; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
        t->prev = p;
        t->next->prev = t;
    }
}

// void insert(int data)
int main()
{
    int A[] = {3, 7, 9, 5};
    int n = sizeof(A) / sizeof(A[0]);
    create(A, n);
    insert(first,7,3);
    display(first);
}