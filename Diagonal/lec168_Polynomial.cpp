#include <iostream>
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
    int j = 0;
    for (j = 0; j < s->n - 1; j++)
    {
        cout << s->e[j].c << "X^" << s->e[j].e << " + ";
    }
    cout << s->e[j].c << "X^" << s->e[j].e << endl;
}
int main()
{
    struct poly p;
    create(&p);
}