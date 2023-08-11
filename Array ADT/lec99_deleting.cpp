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
void append(struct MyArray &arr, int x)
{
    if (arr.length == arr.size)
    {
        cout << "Array is full cant add element\n";
        return;
    }
    arr.a[arr.length] = x;
    cout << "Item inseted at Index: " << arr.length << " of value: " << x << endl;
    arr.length++;
};
void deleteAtIndex(struct MyArray &arr, int index)
{
    cout<<"length"<<arr.length<<endl;
    if (arr.length-1 <index)
    {
        cout << "Index not presenet" << endl;
    }
    else {
        for(int i=index;i<arr.length;i++){
            arr.a[i]=arr.a[i+1];
        }
        arr.length--;
    }
}

int main()
{
    struct MyArray arr;
    int n = 10;
    arr.a = new int[n];
    arr.size = n;
    // display(arr);
    append(arr, 2);
    append(arr, 1);
    append(arr, 24);
    append(arr, 23);
    append(arr, 13);
    append(arr, 25);
    append(arr, 18);

    display(arr);
    deleteAtIndex(arr,7);
    display(arr);
}
