#include <iostream>
#include <vector>
#include<string>
#include <algorithm>

using namespace std;

void bubbleSort(vector<int> &A)
{
    int n = A.size();
    bool flag;
    for (int i = 0; i < n; i++)
    {
        flag = true;
        for (int j = 0; j < ((n - 1) - i); j++)
        {
            if (A[j] > A[j + 1])
            {
                // swap A[j] and A[j+1]
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                flag = false;
            }
        }
        if (flag)
        {
            break;
        }
    }
}

void display(vector<int> A)
{
    if (!A.size())
    {
        cout << "Empty Array provided: " << endl;
        return;
    }
    for (int i = 0; i < A.size(); i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}
void displayStr(vector<string> A)
{
    if (!A.size())
    {
        cout << "Empty Array provided: " << endl;
        return;
    }
    for (int i = 0; i < A.size(); i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void insertSort(vector<int> &A)
{
    int n = A.size(), i, key, j;
    for (i = 1; i < n; i++)
    {
        key = A[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (A[j] > key)
            {
                int temp = A[j];
                A[j] = key;
                A[j + 1] = temp;
            }
        }
    }
}

void selectionSort(vector<int> &A){
    int n=A.size(), min_idx;
    // One by one move boundary of unsorted subarray
    for (int i = 0; i < n-1; i++){
        min_idx=i;
        for(int j=i;j<n;j++){
            // Find the minimum element in remaining array
            if(A[min_idx]>A[j])min_idx=j;
        }
        // Swap the found minimum element with the first element
        int temp=A[min_idx];
        A[min_idx]=A[i];
        A[i]=temp;
    }
}

vector<int>  hashMap(string k){
        vector<int> hash(26,0);
        for(int i=0;i<k.size();i++){
            hash[(k[i]-'a')]++;
        }
        return hash;
    }


int main()
{
    vector<string> j = {"eat","tea","tan","ate","nat","bat"};//8, 99, 91, 33, 15, 47, 84, 20, 79, 5, 70, 88, 61, 44, 97, 96, 12, 78, 23, 76, 87, 14, 50, 18, 36, 95, 64, 83, 55, 7, 72, 42, 16, 65, 40, 69, 11, 85, 2, 10 };
    vector<int> k = { 29, 5, 13, 68, 81, 3, 92, 71, 27, 52, 66, };//8, 99, 91, 33, 15, 47, 84, 20, 79, 5, 70, 88, 61, 44, 97, 96, 12, 78, 23, 76, 87, 14, 50, 18, 36, 95, 64, 83, 55, 7, 72, 42, 16, 65, 40, 69, 11, 85, 2, 10 };
    
    
    
    // cout << "Before Sorting: \n";
    // display(k);
    // cout << " After Sorting: \n";
    // selectionSort(k);
    // display(k);
    // if(hashMap("abc")==hashMap("abf"))cout<<"ff";
    for(int i=0;i<j.size();i++){
        sort(j[i].begin(),j[i].end());
    }
    sort(j.begin(),j.end());
    displayStr(j);
}