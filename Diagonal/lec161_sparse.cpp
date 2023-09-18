#include <iostream>
#include <iomanip>
using namespace std;

struct element
{
    int i;
    int j;
    int x;
};
struct sparse
{
    int i;
    int j;
    int nums;
    struct element *e;
};
void create(struct sparse *s)
{
    cout << "Creating a Spare" << endl;
    cout << "Enter the following:" << endl
         << "Rows: ";
    int nl;
    cin >> s->i;
    cout << "Columns: ";
    cin >> s->j;
    cout << "Elements: ";
    cin >> s->nums;
    s->e = new element[s->nums];
    for (int i = 0; i < s->nums; i++)
    {
        cout << "Row: ";
        cin >> s->e[i].i;
        cout << "Column: ";
        cin >> s->e[i].j;
        cout << "Value: ";
        cin >> s->e[i].x;
        cout << "----- Succesfully Added an Element -----" << endl;
    }
}

void display(struct sparse *s)
{
    int rowWidth = 5;
    int columnWidth = 5;
    int valueWidth = 5;
    cout << "No of rows " << s->i << endl;
    cout << "No of Coulmns " << s->j << endl;
    cout << "No of Non Zero Values " << s->nums << endl;
    cout << "The values are as follows:" << endl;
    // cout << "Row,coulmn,values" << endl;
    cout << left << setw(rowWidth) << "Row "
         << setw(columnWidth) << "Column "
         << setw(valueWidth) << "Value " << endl;
    for (int i = 0; i < s->nums; i++)
    {
        cout << left << setw(rowWidth) << s->e[i].i
             << setw(columnWidth) << s->e[i].j
             << setw(valueWidth) << s->e[i].x << endl;
    }
}
int main()
{
    struct sparse s;
    create(&s);
    display(&s);
    return 0;
}