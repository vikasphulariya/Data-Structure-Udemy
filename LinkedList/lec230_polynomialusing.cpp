#include <iostream>
#include <stdio.h>
using namespace std;

struct Ploy
{
    int val;
    int power;
    struct Ploy *next;
};
void insert(struct Ploy *&head, int c, int pp)
{
    struct Ploy *p;
    p = new Ploy;
    struct Ploy *t = head;
    struct Ploy *back = new Ploy;

    p->val = c;
    p->power = pp;
    if (head == NULL)
    {
        p->next = NULL;
        head = p;
        cout << "success 1\n";
        return;
    }

    while (t)
    {
        if (p->power == t->power)
        {
            // t->power += p->power;
            t->val += p->val;

            cout << "success 3\n";
            return;
        }
        else if (t->power < p->power)
        {
            p->next = t;
            back->next = p;
            // head = p;
            return;
        }
        else
        {
            if (t->next == NULL)
            {
                t->next = p;
                p->next = NULL;
                cout << "success 4\n";
                return;
            }
        }
        back = t;
        t = t->next;
    }
}

void display(struct Ploy *k)
{
    struct Ploy *p = k;
    // cout<<"d";

    while (p)
    {
        if (p->next == NULL)
        {
            printf("%d*x^%d ", p->val, p->power);
            return;
        }
        printf("%d*x^%d + ", p->val, p->power);
        p = p->next;
    }
}
int main()
{
    struct Ploy *head;
    head = new Ploy;
    head = NULL;
    insert(head, 2, 5);
    insert(head, 3, 1);
    insert(head, 3, 3);
    insert(head, 3, 2);
    insert(head, 3, 2);
    insert(head, 3, 10);
    display(head);
}