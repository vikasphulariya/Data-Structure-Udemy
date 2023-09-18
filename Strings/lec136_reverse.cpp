#include <stdio.h>

int main()

{

    char A[] = "Python";

    int i, j;

    for (j = 0; A[j] != '\0'; j++)

    {

    } // close j for loop here to get j as the last index of A

    j = j - 1;

    for (i = 0; i < j; i++, j--)

    {

        char t;

        t = A[i];

        A[i] = A[j];

        A[j] = t;
    }

    printf("%s", A);
}