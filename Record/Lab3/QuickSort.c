#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int l, int r)
{
    int p = A[l];
    int i = l, j = r + 1;
    do
    {
        do {i++; }while (A[i] < p);
        do {j--; }while (A[j] > p);
        swap(&A[i], &A[j]);
    }while(i < j);
    swap(&A[i], &A[j]);
    swap(&A[l], &A[j]);
    return j;
}

void quicksort(int A[], int l, int r)
{
    if(l < r)
    {
        int s = partition(A, l, r);
        quicksort(A, l, s-1);
        quicksort(A, s+1, r);
    }
}

int main()
{
    int A[] = {0, 25, 38, 56, 24, 9, 20, 98};
    quicksort(A, 0, 8);
    for(int i = 0; i < 8; i++)
        printf("%d\t", A[i]);
    return 0;
}
