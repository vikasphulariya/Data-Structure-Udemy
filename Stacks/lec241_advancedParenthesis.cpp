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
        return 0;
    }
    struct Node *p = head;

    head = head->next;
    char x = p->data;
    cout << "Poped:" << p->data << endl;
    delete p;
    return x;
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
bool signMatch(char poped, char pushed)
{
    if (poped == '(' && pushed == ')')
        return true;
    if (poped == '[' && pushed == ']')
        return true;
    if (poped == '{' && pushed == '}')
        return true;
    return false;
}
bool advancedMatching(string a)
{
    struct Node *Head = NULL;

    int n = a.length();
    // cout << sizeof(a.length());
    int balanced = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == '(' || a[i]=='[' || a[i]=='{')
        {
            push(Head, a[i]);
        }
        if (a[i] == ')' || a[i]=='}' || a[i]==']')
        {
            if (isEmpty(Head) || !signMatch(Pop(Head),a[i]))
            {
                // cout << "Not balanced" << endl;
                return 0;
                balanced = 0;
            }
            
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
    string a = "(){}[[]v{i}]ksdddsaa";
    cout << (advancedMatching(a) ? "Matched" : "Not Mateched") << endl;
}
