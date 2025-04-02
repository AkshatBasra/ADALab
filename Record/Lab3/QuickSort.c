#include <stdio.h>
#include <time.h>
#include <stdlib.h>

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

int* generate_random_integers(int n) {
    // Allocate memory for the array
    int *arr = (int*) malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Seed the random number generator
    srand(time(NULL));

    // Generate n random integers between 100 and 200
    for (int i = 0; i < n; i++) {
        arr[i] = (rand() % 1000);  // Generates numbers between 100 and 200
    }

    return arr;
}

int main()
{
    int A[] = {0, 25, 38, 56, 24, 9, 20, 98};
    int n = 1000000;
    //int AB[n], i;
    srand(time(0));

    int *AB = generate_random_integers(n);

    clock_t start, end;
    start = clock();
    //quicksort(A, 0, 8);
    quicksort(AB, 0, n);
    end = clock();
    for(int i = 0; i < n; i++)
        printf("%d\t", AB[i]);
    double t = (end - start)/CLK_TCK;
    printf("\nClock: %lf", (double)(end - start)/CLK_TCK);
    return 0;
}
