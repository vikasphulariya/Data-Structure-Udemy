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

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    Create(A, 5);
    display(head);
}
