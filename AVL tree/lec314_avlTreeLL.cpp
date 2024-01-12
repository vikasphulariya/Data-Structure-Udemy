#include <iostream>
using namespace std;

struct treeNode
{
    int data;
    int hieght;
    struct treeNode *left;
    struct treeNode *right;
} *root = NULL;

int NodeHieght(struct treeNode *r)
{
    int h1, h2;
    h1 = r && r->left ? r->left->hieght : 0;
    h2 = r && r->right ? r->right->hieght : 0;
    return h1 > h2 ? h1 + 1 : h2 + 1;
}

int balancefactor(struct treeNode *r)
{
    int h1, h2;
    h1 = r && r->left ? r->left->hieght : 0;
    h2 = r && r->right ? r->right->hieght : 0;
    return h1 - h2;
}

struct treeNode *llRotation(struct treeNode *r)
{
    struct treeNode *pl = r->left;
    struct treeNode *plr = pl->right;

    pl->right = r;
    r->left = plr;
    r->hieght = NodeHieght(r);
    pl->hieght = NodeHieght(pl);
    if (r == root)
    {
        root = pl;
    }
    return pl;
}
struct treeNode *rlRotation(struct treeNode *r)
{
    struct treeNode *pr = r->right;
    struct treeNode *prl = pr->left;
    r->right = prl->left;
    pr->left = prl->right;
    prl->left = r;
    prl->right = pr;
    pr->hieght = NodeHieght(pr);
    r->hieght = NodeHieght(r);
    prl->hieght=NodeHieght(prl);
 
    if (r == root)
    {
        root = prl;
    }
    return prl;
}
struct treeNode *lrRotation(struct treeNode *r)
{
    struct treeNode *pl = r->left;
    struct treeNode *plr = pl->right;
    r->left = plr->right;
    pl->right = plr->left;
    plr->right = r;
    plr->left = pl;
    pl->hieght = NodeHieght(pl);
    r->hieght = NodeHieght(r);
    plr->hieght = NodeHieght(plr);
    if (r == root)
    {
        root = plr;
    }
    return plr;
}
struct treeNode *rrRotation(struct treeNode *r)
{
    struct treeNode *pr = r->right;
    struct treeNode *prl = pr->left;

    pr->left = r;
    r->right = prl;
    r->hieght = NodeHieght(r);
    pr->hieght = NodeHieght(pr);
    if (r == root)
    {
        root = pr;
    }
    return pr;
}
struct treeNode *createBST(struct treeNode *root, int data)
{
    if (root == NULL)
    {
        struct treeNode *temp = new treeNode;
        temp->data = data;
        temp->hieght = 1;
        temp->left = temp->right = NULL;
        return temp;
    }
    else if (data == root->data)
    {
        cout << "element exist alreay";
        return NULL;
    }
    if (data < root->data)
    {
        root->left = createBST(root->left, data);
    }
    else
    {
        root->right = createBST(root->right, data);
    }
    root->hieght = NodeHieght(root);
    if (balancefactor(root) == 2 && balancefactor(root->left) == 1)
    {
        return llRotation(root);
    }
    else if (balancefactor(root) == 2 && balancefactor(root->left) == -1)
    {
        return lrRotation(root);
    }
    else if (balancefactor(root) == -2 && balancefactor(root->right) == 1)
    {
        return rlRotation(root);
    }
    else if (balancefactor(root) == -2 && balancefactor(root->right) == -1)
    {
        return rrRotation(root);
    }
    return root;
}
void display(struct treeNode *p)
{
    struct treeNode *temp = p;
    cout << "ddd";
}
struct treeNode *predecessor(struct treeNode *t)
{
    while(t && t->right != NULL)
    {
        t = t->right;
    }
 
    return t;
}
 
struct treeNode *successor(struct treeNode *t)
{
    while(t && t->left != NULL)
    {
        t = t->left;
    }
 
    return t;
}

struct treeNode *Delete(struct treeNode *t , int key)
{
    struct treeNode *q;
 
    if(t == NULL)
    {
        return 0;
    }
    if(t->left == NULL && t->right == NULL)
    {
        if(t==root)
        {
            root = NULL;
        }
        free(t);
        return 0;
    }
 
    if(key < t->data)
    {
        t->left = Delete(t->left , key);
    }
    else if(key > t->data)
    {
        t->right = Delete(t->right , key);
    }
    else
    {
        if(NodeHieght(t->left) > NodeHieght(t->left))
        {
            q = predecessor(t->left);
            t->data = q->data;
            t->left = Delete(t->left , q->data);
        }
        else
        {
            q = successor(t->right);
            t->data = q->data;
            t->right = Delete(t->right , q->data);
        }
    }
 
        t->hieght = NodeHieght(t);
 
        if(balancefactor(t) == 2 && balancefactor(t->left) == 1)
        {
            return llRotation(t);
        }
        else if(balancefactor(t) == -2 && balancefactor(t->right) == -1)
        {
            return rrRotation(t);
        }
        else if(balancefactor(t) == -2 && balancefactor(t->right) == 1 )
        {
            return rlRotation(t);
        }
        else if(balancefactor(t) == 2 && balancefactor(t->right) == -1)
        {
            return lrRotation(t);
        }
        else if(balancefactor(t) == 2 && balancefactor(t->left) == 0)
        {
            return llRotation(t);
        }
        else if(balancefactor(t) == -2 && balancefactor(t->right) == 0)
        {
            return rrRotation(t);
        }
 
    return t;
}
int main()
{
    // root=new treeNode;
    // root=NULL;
    cout << "hi";
    root = createBST(root, 10);
    createBST(root, 20);
    createBST(root, 30);
    createBST(root, 25);
    createBST(root, 28);
    createBST(root, 27);
    createBST(root, 5);
    display(root);
    return 0;
}