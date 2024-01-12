#include <iostream>
using namespace std;
struct treeNode
{
    struct treeNode *left;
    int data;
    struct treeNode *right;
};

struct Node
{
    struct treeNode *data;
    struct Node *next;
};
struct Queue
{
    struct Node *front = NULL;
    struct Node *last = NULL;
};

class Tree
{
private:
    struct Queue *q = new Queue;
    struct treeNode *p, *t;

public:
    struct treeNode *root;
    bool isEmpty()
    {
        if (q->front == NULL)
        {
            return true;
        }
        return false;
    };


    treeNode * dequeue(){
    struct treeNode* x=NULL;
    if(q->front==NULL){
        cout<<"Queue is empty"<<endl;
        return x;
    }
    if(q->front==q->last){
        // cout<<"eee"<<endl;
        x=q->front->data;
        q->front=NULL;
        q->last=NULL;
        return x;
    }
    struct Node* temp=q->front;
    x=q->front->data;
    q->front=q->front->next;
    return x;
};
    void enqueue(treeNode *data)
    {
        struct Node *temp = new Node;
        temp->data = data; // assuming the user will enter a number for this field.
        temp->next = NULL;
        if (q->front == NULL)
        {
            q->front = temp;
            q->last = temp;
        }
        else
        {
            q->last->next = temp;
            q->last = temp;
        }
    };

    void display()
    {
        if (isEmpty())
        {
            cout << "The queue is Empty!" << endl;
            return;
        }
        struct Node *j = new Node;
        j = q->front;
        while (j)
        {
            cout << j->data << " ";
            j = j->next;
        }
        cout << endl;
    };

    void createTree()
    {
        // struct treeNode *p,*t;
        root = new treeNode;
        int x;
        // struct Queue *q=new Queue;
        cout << "Enter root value:";
        cin >> x;
        root->data = x;
        root->left = root->right = NULL;
        enqueue(root);

        while (!isEmpty())
        {
            p = dequeue();
            cout << "enter left child of " << p->data << " ";
            cin >> x;
            if (x != -1)
            {
                t = new treeNode;
                t->data = x;
                t->left = t->right = NULL;
                p->left = t;
                enqueue(t);
            }
            cout << "enter right child " << p->data << " ";
            cin >> x;
            if (x != -1)
            {
                t = new treeNode;
                t->data = x;
                t->left = t->right = NULL;
                p->right = t;
                enqueue(t);
            }
        }
    }
    int Height(treeNode *rootk) {
    int l = 0;
    int r = 0;
    if (rootk == nullptr){
        return 0;
    }
 
    l = Height(rootk->left);
    r = Height(rootk->right);
    if (l > r){
        return l + 1;
    } else {
        return r + 1;
    }
}

    void preOrder(struct treeNode *root)
    {
        if (root)
        {
            cout << root->data << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }
};

// struct treeNode *root=NULL;

int
main()
{
    Tree onj1;
    onj1.createTree();
-    onj1.preOrder(onj1.root);
    cout<<"\n"<<onj1.Height(onj1.root);
    // createTree();
    // preOrder(root);
}
