#include <iostream>
using namespace std;
struct Stack
{
    int size;
    int top;
    int *Array;
};

void
create(struct Stack *&st)
{
    cout << "Enter Stack Size:";
    cin >> st->size;
    st->top = -1;
    st->Array = new int[st->size];
}

void push(struct Stack *&st, int value)
{
    if ((st->top + 1) == st->size)
    {
        cout << "Stack is full\n";
        return;
    }
    st->Array[++st->top] = value;
    cout << "Element Pushed\n";
}

void display(struct Stack *p)
{
    int i;
    if ((p->top) == -1)
    {
        cout << "stack is empty\n";
        return;
    }
    for (i = p->top; i >= 0; i--)
    {
        cout << p->Array[i] << endl;
    }
}
bool isFull(struct Stack *p)
{
    if (p->size == p->top + 1)
    {
        return true;
    }
    else{
        return false;
    }
        return false;
}

int pop(struct Stack *&p){
    if(p->top==-1){
        cout<<"Stack Underflow \n";
        return 0;
    }
    int x=p->Array[p->top--];
    cout<<"Poped "<<x<<endl;
    return x;

}

int main(){
    struct Stack *st;
    create(st);
    push(st,1);
    push(st,2);
    push(st,3);
    push(st,4);
    push(st,5);
    push(st,6);
    cout<<(isFull(st)?"true":"false")<<endl;
    display(st);
    pop(st);
    pop(st);
    pop(st);
    pop(st);
    pop(st);
    pop(st);
}