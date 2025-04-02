#include <stdio.h>

void merger(int[], int, int[], int, int[]);

void mergesort(int A[], int n)
{
    if(n > 1)
    {
        int half;
        if(n % 2 == 0)
        {
            half = n/2;
        }
        int B[half], C[half];
        for(int i = 0; i < half; i++)
        {
            B[i] = A[i];
            C[i] = A[half + i];
        }
        mergesort(B, half);
        mergesort(C, half);
        merger(B, half, C, half, A);
    }
}

void merger(int B[], int p, int C[], int q, int A[])
{
    int i = 0, j = 0, k = 0;
    while(i < p && j < q)
    {
        if(B[i] <= C[j])
        {
            A[k] = B[i];
            i++;
        }
        else
        {
            A[k] = C[j];
            j++;
        }
        k++;
    }
    while(j < q)
    {
        A[k] = C[j];
        j++;
        k++;
    }
    while(i < p)
    {
        A[k] = B[i];
        i++;
        k++;
    }
}

int main()
{
    int A[] = {0, 25, 38, 56, 24, 9, 20, 98};
    mergesort(A, 8);
    for(int i = 0; i < 8; i++)
        printf("%d\t", A[i]);
}
