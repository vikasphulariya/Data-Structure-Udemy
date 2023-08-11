#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct MyArray
{
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
}

void set(struct MyArray &arr, int index, int value)
{
    if (arr.length < index)
    {
        cout << "Index out of range valid till" << arr.length << endl;
        return;
    }
    arr.a[index] = value;
    if(arr.length==index)arr.length++;
    cout << "Value at index " << index << " is updated with value " << value << endl;
}
void get(struct MyArray &arr, int index)
{
    if (arr.length <= index)
    {
        cout << "Index out of range valid till" << arr.length << endl;
        return;
    }
    cout << "Value at index " << index << " is " << arr.a[index] << endl;
}

void max(struct MyArray &arr)
{
    int max = arr.a[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (max < arr.a[i])
            max = arr.a[i];
    }
    cout << "Max value is " << max << endl;
}
void min(struct MyArray &arr)
{
    int min = arr.a[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (min > arr.a[i])
            min = arr.a[i];
    }
    cout << "min value is " << min << endl;
}

void sum(struct MyArray &arr)
{
    int sum = arr.a[0];
    for (int i = 1; i < arr.length; i++)
    {
        // if (min > arr.a[i])
        sum = sum + arr.a[i];
    }
    cout << "sum is value is " << sum << endl;
}
void avg(struct MyArray &arr)
{
    int sum = arr.a[0];
    for (int i = 1; i < arr.length; i++)
    {
        // if (min > arr.a[i])
        sum = sum + arr.a[i];
    }
    cout << "avg is value is " << (sum / arr.length) << endl;
}

int main()
{
    struct MyArray arr;
    int n = 10;
    arr.a = new int[n];
    arr.size = n;
    display(arr);
    append(arr, 2);
    append(arr, 1);
    append(arr, 24);
    append(arr, 23);
    append(arr, 13);
    display(arr);
    max(arr);
    min(arr);
    avg(arr);
    sum(arr);
    // cout<<arr.length;
    get(arr,3);
    set(arr,5,5);
    display(arr);

}
