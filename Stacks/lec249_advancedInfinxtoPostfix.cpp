#include <iostream>
using namespace std;
struct Node
{
    char data;
    int pre;
    struct Node *next;
};
void push(struct Node *&Head, char data, int pre)
{
    struct Node *temp = new Node();
    if (temp == NULL)
    {
        cout << "Stack is full";
    }
    temp->data = data;
    temp->pre = pre;
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

int precedence(char a)
{
    if (a == '+' || a == '-')
        return 1;
    if (a == '/' || a == '*')
        return 3;
    if (a == '^' )
        return 6;
    return -1;
}
int precedenceStack(char a)
{
    if (a == '+' || a == '-')
        return 2;
    if (a == '/' || a == '*')
        return 4;
    if (a == '^' )
        return 5;
    return -1;
}

string prifixToPostfix(string a)
{
    struct Node *Head = NULL;
    string result = "";
    for (int i = 0; a[i] != '\0'; i++)
    {
        if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/')
        {
            int x = precedence(a[i]);
            if (Head == NULL or Head->pre < x)
            {
                cout << "1" << endl;
                push(Head, a[i], precedenceStack(a[i]));
                continue;
            }
            while (Head != NULL && Head->pre >= x)
            {
                cout << "2" << endl;
                result = result + Pop(Head);
            }
            push(Head, a[i], precedenceStack(a[i]));
        }
        else if( a[i] == '('){
            push(Head,a[i],precedence(a[i]));
        }
        else if(a[i] == ')'){
            while(Head->data!='('){
                result +=Pop(Head);
            }
            Pop(Head);
        }
        else
        {
            result += a[i];
        }
    }
    while (!isEmpty(Head))
    {
        result += Pop(Head);
    }
    cout << endl;
    return result;
}




int main()
{
    string a = "2+4/5*(5-3)^5^4";
    cout<< (prifixToPostfix(a)) << endl;
}
