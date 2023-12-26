#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
void push(struct Node *&Head, int data)
{
    struct Node *temp = new Node();
    if (temp == NULL)
    {
        cout << "Stack is full";
    }
    temp->data = data;
    temp->next = Head;
    Head = temp;
    cout << "Inserted " << Head->data << endl;
}
void Pop(struct Node *&head)
{
    if (head == NULL)
    {
        cout << "Stack Is empty" << endl;
        return;
    }
    struct Node *p = head;

    head = head->next;
    cout << "Poped:" << p->data << endl;
    delete p;
}

void display(struct Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
bool isEmpty(struct Node *head)
{
    if (head == NULL)
    {

        return true;
    }
    return false;
}

int main()
{
    struct Node *Head = NULL;
    push(Head, 1);
    push(Head, 8);
    push(Head, 4);
    push(Head, 2);
    display(Head);
    Pop(Head);
    Pop(Head);
    Pop(Head);
    cout<<(isEmpty(Head)?"true":"false")<<endl;
    Pop(Head);
    Pop(Head);
}
