#include <iostream>
using namespace std;

class Diagonal
{
private:
    int *A;
    int n;

public:
    Diagonal()
    {
        n = 2;
        A = new int[2];
    };
    Diagonal(int n)
    {
        this->n = n;
        A = new int[n];
    };
    void Set(int i, int j, int x)
    {
        if (i == j)
        {
            A[i - 1] = x;
        }
    };
    int Get(int i, int j)
    {
        if (i == j)
        {
            return A[i - 1];
        }
        else
            return 0;
    };
    void Display()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    cout <<" "<< A[i];
                }
                else
                {
                    cout<<" "<< 0;
                }
            }
            cout <<endl;
        }
    };
};
int main()
{
    Diagonal obj(5);
    obj.Set(1, 1, 2);
    obj.Set(2, 2, 5);
    obj.Set(3, 3, 56);
    obj.Set(4, 4, 6);
    obj.Set(5, 5, 4);
    obj.Display();
    return 0;
}