#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<int> &A, int l, int mid, int h)
{
    // cout<<mid<<" "<<l<<" "<<h;
    int m = mid;
    int i = l, j = m + 1;
    vector<int> C;
    while (i <= m && j <= h)
    {
        cout << "Comparing " << A[i] << " " << A[j] << " ";
        if (A[i] < A[j])
        {
            cout << "pushed " << A[i] << endl;
            C.push_back(A[i++]);
        }
        else
        {
            cout << "pushed " << A[j] << endl;
            C.push_back(A[j++]);
        }
    }
    while (i <= m)
    {
        C.push_back(A[i++]);
    }
    while (j <= h)
    {
        C.push_back(A[j++]);
    }
    for (int i = l; i <= h; i++)
    {
        A[i] = C[i - l];
    }
    cout << endl;
}

void IMergeSort(vector<int> &A)
{
    int p, i, l, mid, h;
    for (p = 2; p <= A.size(); p = p * 2)
    {
        for (i = 0; i + p - 1 < A.size(); i = i + p)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            Merge(A, l, mid, h);
        }
        if ((A.size() - i) > p / 2)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            Merge(A, l, mid, A.size() - 1);
        }
    }
    if (p / 2 < A.size())
    {
        cout << "d" << p / 2 << endl;
        Merge(A, 0, (p / 2 - 1), A.size() - 1);
    }
}


void Rmerge(vector<int> &A, int l, int h)
{
    int mid = (l + h) / 2;
    if (l < h)
    {
        Rmerge(A, l, mid);
        Rmerge(A, mid + 1, h);
        Merge(A, l, mid, h);
    }
}

void display(vector<int> A)
{
    if (!A.size())
    {
        cout << "Empty Array:" << endl;
        return;
    }
    for (int i = 0; i < A.size(); i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> A = {
        2,
        5,
        8,
        12,
        3,
        6,
        7,
        10,
    };
    cout << "Original Array:";
    display(A);
    Rmerge(A, 0, A.size()-1);
    cout << "Sorted Array: ";
    display(A);
}