#include <iostream>
using namespace std;
struct MyArray
{
    int a[10];
    int length = 0;
    int size=10;
};

void display(struct MyArray x)
{
    if (x.length == 0)
    {
        printf("Empty Array Nothing to Display\n");
        return;
    }
    for (int i = 0; i < x.length; i++)
    {
        cout << "At index: " << i << " The value is " << x.a[i] << endl;
    }
}

void append(struct MyArray &arr, int value)
{
    if (arr.length == arr.size)
    {
        cout << "Array full" << endl;
        return;
    }
    arr.a[arr.length] = value;
    arr.length++;
}
void merge(struct MyArray &arr1, struct MyArray &arr2, struct MyArray &finalArr)
{
    int t = arr1.length + arr2.length;
    // finalArr.a = new int[t];
    // finalArr.size = t;
    finalArr.length = 0;
    int j = 0, k = 0;
    for (int i; i < t; i++)
    {
        if(j>=arr1.length){
            finalArr.a[i]=arr2.a[k];
            finalArr.length++;
            k++;
            continue;
        }
        if(k>=arr2.length){
            finalArr.a[i]=arr1.a[j];
            finalArr.length++;
            j++;
            continue;
        }
        if(arr1.a[j]<arr2.a[k]){
            finalArr.a[i]=arr1.a[j];
            finalArr.length++;
            j++;
        // cout<<"merge ";
        }
        else{
            finalArr.a[i]=arr2.a[k];
            k++;
            finalArr.length++;
            
        }
    }
};

int main()
{
    struct MyArray arr;
    // arr.a = new int[10];
    arr.size = 10;
    struct MyArray arr1;
    // arr1.a = new int[10];
    arr1.size = 10;
    append(arr, 2);
    append(arr, 12);
    append(arr, 21);
    append(arr, 32);
    cout << "Elements of Array are:" << endl;
    display(arr);
    append(arr1, 1);
    append(arr1, 11);
    append(arr1, 23);
    append(arr1, 45);
    cout << "elementss of arr1 are:" << endl;
    display(arr1);
    struct MyArray arr2;
    merge(arr,arr1,arr2);
    cout<<"after merging"<<endl;
    display(arr2);
}
