#include <iostream>
using namespace std;
struct Node
{
    char data;
    struct Node *next;
};
void push(struct Node *&Head, char data)
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
char Pop(struct Node *&head)
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

bool simpleParnethesis(string a)
{
    struct Node *Head = NULL;

    int n = a.length();
    // cout << sizeof(a.length());
    int balanced = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == '(')
        {
            push(Head, '(');
        }
        if (a[i] == ')')
        {
            if (isEmpty(Head))
            {
                // cout << "Not balanced" << endl;
                return 0;
                balanced = 0;
            }
            Pop(Head);
        }
    }
    if (!isEmpty(Head))
    {
        // cout << "Not balanced" << endl;
        return 0;
        // break;
    }
    else
    {
        // cout << "balanced";
        return 1;
    }
}

int main()
{
    string a = "()viksdddsaa";
    cout<<(simpleParnethesis(a)?"Matched":"Not Mateched")<<endl;
}
