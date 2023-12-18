#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void create(int A[], int n)
{
    struct Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
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

int Rcount(struct Node *p)
{
    if (p)
    {
        return (Rcount(p->next) + 1);
    }
    else
    {
        return 0;
    }
}


int sum(struct Node *p){
    int sum=0;
    while(p){
        sum=sum+p->data;
        p=p->next;
    }
    return sum;

}

int Rsum(struct Node *p){
    if(p){
        return (p->data + Rsum(p->next));
    }
    else{
        return 0;
    }
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    int n = sizeof(A) / sizeof(A[0]);
    create(A,n);
    cout<<count(first)<<" "<<Rcount(first)<<endl;
    cout<<sum(first)<<" "<<Rsum(first);
}
