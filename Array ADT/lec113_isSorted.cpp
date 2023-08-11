#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct MyArray
{
    int n;
    int *a;
    int size;
    int length = 0;
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
void appdend(struct MyArray &arr, int x)
{
    if (arr.length == arr.size)
    {
        cout << "Array is full cant add element\n";
        return;
    }
    arr.a[arr.length] = x;
    cout << "Item inseted at Index: " << arr.length << " of value: " << x << endl;
    arr.length++;
}
void appendSorted(struct MyArray &arr, int x)
{
    if (arr.length > arr.size)
    {
        cout << "Array is full cant add element\n";
        return;
    }
    if(arr.length==0){
        arr.a[0]=x;
            cout << "Item inseted at Index: " << arr.length << " of value: " << x << endl;
        arr.length++;
        return;

    }
    int temp;
    for(int i=arr.length;-1<i;i--){
        if(arr.a[i-1]<=x){
            arr.a[i]=x;
    cout << "Item inseted at Index: " << i<< " of value: " << x << endl;
            break;
        }
        else{
            arr.a[i]=arr.a[i-1];
    cout << "Item inseted at Index: " << i<< " of value: " << x << endl;
        }
    }
    arr.length++;
}

void isSorted(struct MyArray &arr)
{
    bool s=true;
    int j = arr.a[0];
    for (int i = 1; i < arr.length; i++)
    {
        if ( j <= arr.a[i]){
            j=arr.a[i];
        }
        else{
            s=false;
            break;
        }
    }
    if(s){

    cout<<"Array is sorted"<<endl;
    return;
    }
    cout<<"Array is not sorted"<<endl;
}

int main()
{
    struct MyArray arr;
    int n = 10;
    arr.a = new int[n];
    arr.size = n;
    display(arr);
    appendSorted(arr, 13);
    appendSorted(arr, 24);
    appendSorted(arr, 2);
    appendSorted(arr, 23);
    appendSorted(arr, 1);
    display(arr);
    // isSorted(arr);
    // display(arr);
}
