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
        cout <<"At index: "<<i<<" The value is "<< x.a[i] << endl;
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
    cout<<"Item inseted at Index: "<<arr.length<<" of value: "<<x<<endl;
    arr.length++;
}

void insert(struct MyArray &arr,int index,int x){
    if (arr.length == arr.size)
    {
        cout << "Array is full cant insert element\n";
        return;
    }
    else if(index<=arr.length){
        cout<<"length is"<<arr.length<<endl;
        for(int i=arr.length;i>index;i--){
            arr.a[i]=arr.a[i-1];
        }
        arr.a[index]=x;
        arr.length++;
        cout<<"New item Inserted at Index "<<index<<" for value "<<x<<endl;
        return;
    }
    cout<<"Invalid Index provided"<<endl;
    cout<<"Either Provide Index Smaller Then or equal to "<<arr.length<<endl;
    cout<<"Or you can use Append() Function"<<endl;

}

int main()
{
    struct MyArray arr; 
    int n = 10;
    arr.a = new int[n];
    arr.size = n;
    display(arr);
    append(arr,2);
    append(arr,1);
    append(arr,24);
    append(arr,23);
    append(arr,13);
    append(arr,2);
    append(arr,1);
    append(arr,24);
    append(arr,23);
    append(arr,13);
    append(arr,2);
    append(arr,1);
    append(arr,24);
    append(arr,23);
    append(arr,13);
    display(arr);
    insert(arr,0,20);
    display(arr);
}
