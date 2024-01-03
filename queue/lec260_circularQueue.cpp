#include<iostream>
using namespace std;
struct Queuek
{
    int front;
    int rear;
    int size;
    int *array;
};
class Queue
{
private:
    struct Queuek *p=new Queuek;

public:
    Queue()
    {
        
        p->front = 0;
        p->rear = 0;
        // cout << "Enter the number of elements you want in queue: ";
        // cin >> p->size;
        p->size=5;
        p->array = new int[5];
    }
    Queue(int n)
    {
        // p = new Queue;
        p->front = 0;
        p->rear = 0;
        // cout << "Enter the number of elements you want in queue: ";
        // cin >> p->size;
        p->size=n;
        p->array = new int[n];
    }
    ~Queue()
    {
        delete p;
    }
    void enqueue(int x)
    {
        if (((p->rear+1)%p->size) == p->front)
        {
            cout << "array full" << endl;
            return;
        }
        p->rear=(p->rear+1)%p->size;
        p->array[p->rear] = x;
    }
    void dequeue()
    {
        if (p->front == p->rear)
        {
            cout << "empty Queue" << endl;
            return;
        }
        p->front=((p->front+1)%p->size);
        cout << "Element deleted from Queue is : " << p->array[p->front] << endl;
    }
    bool isEmpty()
{
    if (p->front == p->rear)
    {
        return true;
    }
    return false;
    
}
void display()
{
    if (isEmpty())
    {
        cout << "empty queue" << endl;
        return;
    }
    int i=p->front+1;
    do
    {
        cout<<i<<" " << p->array[i] << " "<<p->size<<endl;
        i=(1+i)%p->size;
    }while (i!=((p->rear+1)%p->size));
    
    
    cout << endl;
};
};
int main()
{
    // struct Queue *q = new Queue;
    Queue obj1;
    cout<<(obj1.isEmpty()?"true":"false")<<endl;
    obj1.enqueue(2);
    obj1.enqueue(5);
    obj1.enqueue(6);
    obj1.enqueue(6);
    obj1.enqueue(6);
    obj1.enqueue(6);
    obj1.enqueue(6);
    obj1.enqueue(6);
    obj1.enqueue(6);
    obj1.enqueue(6);
    obj1.enqueue(6);
    obj1.enqueue(6);
    obj1.enqueue(6);
    obj1.enqueue(6);
    obj1.enqueue(6);
    obj1.enqueue(7);
    obj1.dequeue();
    obj1.enqueue(11);
    obj1.display();

    return 1;
}