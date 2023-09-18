#include <iostream>
#include <math.h>
using namespace std;
struct term
{
    int c;
    int e;
};
struct poly
{
    int n;
    struct term *e;
};
void display(struct poly *s)
{
    int j = 0;
    for (j = 0; j < s->n - 1; j++)
    {
        cout << s->e[j].c << "X^" << s->e[j].e << " + ";
    }
    cout << s->e[j].c << "X^" << s->e[j].e << endl;
}

void create(struct poly *s)
{
    cout << "No of elements: ";
    cin >> s->n;
    s->e = new term[s->n];
    for (int i = 0; i < s->n; i++)
    {
        cout << "Enter Coefficent:";
        cin >> s->e[i].c;
        cout << "Enter Exponent:";
        cin >> s->e[i].e;
    }
    cout << "Successfuly Created Polynomial" << endl;
    display(s);
}

void add(struct poly *s, struct poly *p, struct poly *sum)
{
    cout << "Adding\n";
    int i = 0, j = 0, n = 0;
    sum->n = s->n + p->n;
    sum->e = new term[s->n];
    while (i < s->n && j < p->n)
    {
        if (s->e[i].e == p->e[j].e)
        {
            sum->e[n].e = s->e[i].e;
            sum->e[n++].c = s->e[i++].c + p->e[j++].c;
        }
        else
        {
            if (s->e[i].e > p->e[j].e)
            {
                sum->e[n++] = s->e[i++];
            }
            else
            {
                sum->e[n++] = p->e[j++];
            }
        }
    }
    while (i < s->n)
    {
        sum->e[n++] = s->e[i++];
    }
    while (j < p->n)
    {
        sum->e[n++] = p->e[j++];
    }
    sum->n = n;
}

int caluclate(struct poly *s)
{
    int x;
    cout << "Enter value of X:";
    cin >> x;
    int sum = 0, j = 0;
    for (j = 0; j < s->n; j++)
    {
        //     cout << s->e[j].c << "X^" << s->e[j].e << " + ";
        // cout << s->e[j].c << "X^" << s->e[j].e << endl;
        sum = sum + (s->e[j].c * pow(x, s->e[j].e));
    }
    return sum;
}
int main()
{
    struct poly p1;
    struct poly p2;
    struct poly sum;
    create(&p1);
    cout << caluclate(&p1);
    // create(&p2);
    // add(&p1, &p2, &sum);
    // display(&sum);
}