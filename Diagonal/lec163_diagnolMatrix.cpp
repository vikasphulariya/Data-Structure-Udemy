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

void displayMatrix(struct sparse *s)
{
    int k = 0;
    for (int i = 1; i <= s->i; i++)
    {
        for (int j = 1; j <= s->j; j++)
        {
            if (j == s->e[k].j && i == s->e[k].i)
            {
                cout << s->e[k++].x << " ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}
int add(struct sparse *s, struct sparse *k, struct sparse *sum)

{
    if (s->i != k->i && s->j != k->j)
    {
        cout << "cant Add" << endl;
        return 0;
    }
    // cout << "adding started\n";
    int i = 0, j = 0, n = 0;
    sum->i = s->i;
    sum->j = s->j;
    sum->nums = s->nums + k->nums;
    sum->e = new element[sum->nums];
    while (i <= s->nums && j <= k->nums)
    {
        // cout << "enetered while" << endl;
        if (s->e[i].i == k->e[j].i && s->e[i].j == k->e[j].j)
        {
            // cout << "same i and j" << endl;

            sum->e[n].i = s->e[i].i;
            sum->e[n].j = s->e[i].j;
            sum->e[n++].x = s->e[i++].x + k->e[j++].x;
        }
        else
        {
            // cout << "not same i and j" << endl;
            if (s->e[i].i < k->e[j].i)
            {
                // sum->e[n].i = s->e[i].i;
                // sum->e[n].j = s->e[i].j;
                sum->e[n++] = s->e[i++];
            }
            else if (s->e[i].i > k->e[j].i)
            {
                // sum->e[n].i = k->e[j].i;
                // sum->e[n].j = k->e[j].j;
                sum->e[n++] = k->e[j++];
            }
            else
            {

                if (s->e[i].j < k->e[j].j)
                {
                    // sum->e[n].i = s->e[i].i;
                    // sum->e[n].j = s->e[i].j;
                    sum->e[n++] = s->e[i++];
                }
                else
                {
                    // sum->e[n].i = k->e[j].i;
                    // sum->e[n].j = k->e[j].j;
                    sum->e[n++] = k->e[j++];
                }
            }
        }
    }
    while (i <= s->nums)
    {
        cout << "Extra in first matrix" << endl;
        // sum->e[n].i = s->e[i].i;
        // sum->e[n].j = s->e[i].j;
        sum->e[n++] = s->e[i++];
    }
    while (j <= k->nums)
    {
        cout << "Extra in second matrix" << endl;
        // sum->e[n].i = k->e[j].i;
        // sum->e[n].j = k->e[j].j;
        sum->e[n++] = k->e[j++];
    }
    cout << "Adding Done" << endl;
    return 1;
}

int main()
{
    struct sparse s;
    struct sparse k;
    struct sparse sum;
    create(&s);
    cout << "Matrix 1" << endl;
    displayMatrix(&s);
    create(&k);
    cout << "Matrix 2" << endl;
    displayMatrix(&k);
    // // display(&s);
    add(&s, &k, &sum);

    cout << "Matrix 1" << endl;
    displayMatrix(&s);
    cout << "Matrix 2" << endl;
    displayMatrix(&k);
    cout << "Matrix sum" << endl;
    displayMatrix(&sum);
    return 0;
}