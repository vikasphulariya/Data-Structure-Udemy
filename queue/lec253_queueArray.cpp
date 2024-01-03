#include <iostream>
using namespace std;
struct Queue
{
    int front;
    int rear;
    int size;
    int *array;
};
void CreateQueue(struct Queue *&p)
{
    p->front = -1;
    p->rear = -1;
    // cout << "Enter the number of elements you want in queue: ";
    // cin >> p->size;
    p->array = new int[5];
}
void enqueue(struct Queue *&p, int i)
{
    if (p->rear == p->size)
    { // empty condition
        cout << "array full" << endl;
        return;
    }
    p->array[++p->rear] = i;
    // cout<<p->rear<<endl;
}
void dequeue(struct Queue *&p)
{
    if (p->front == p->rear)
    {
        cout << "empty Queue" << endl;
        return;
    }
    cout << "Element deleted from Queue is : " << p->array[++p->front] << endl;
}
bool isEmpty(struct Queue *p)
{
    if (p->front == p->rear)
    {
        return true;
    }
    return false;
}
void display(struct Queue *p)
{
    if (isEmpty(p))
    {
        cout << "empty queue" << endl;
        return;
    }
    for (int i = (p->front + 1); i <= p->rear; i++)
    {
        cout << p->array[i] << " ";
    }
    cout << endl;
}

int main()
{
    struct Queue *q = new Queue;

    return 1;
}