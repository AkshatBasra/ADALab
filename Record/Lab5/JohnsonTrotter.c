#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int findMobile(int arr[], int dir[], int n)
{
    int mobile = 0;
    int mobileIndex = -1;

    for (int i = 0; i < n; i++)
    {
        if ((dir[arr[i] - 1] == 0 && i > 0 && arr[i] > arr[i - 1]) || (dir[arr[i] - 1] == 1 && i < n - 1 && arr[i] > arr[i + 1]))
        {
            if (arr[i] > mobile)
            {
                mobile = arr[i];
                mobileIndex = i;
            }
        }
    }
    return mobileIndex;
}

void johnsonTrotter(int n)
{
    // Working Array
    int *arr = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }

    // Direction Array
    int *dir = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        dir[i] = 0;
    }

    printArray(arr, n);

    int mobileIndex;
    while ((mobileIndex = findMobile(arr, dir, n)) != -1)
    {
        int mobileElement = arr[mobileIndex];
        int pos = mobileIndex;

        if (dir[mobileElement - 1] == 0)
        {
            swap(&arr[pos], &arr[pos - 1]);
            pos--;
        }
        else
        {
            swap(&arr[pos], &arr[pos + 1]);
            pos++;
        }

        for (int i = 0; i < n; i++)
        {
            if (arr[i] > mobileElement)
            {
                dir[arr[i] - 1] = !dir[arr[i] - 1];
            }
        }
        printArray(arr, n);
    }
    free(arr);
    free(dir);
}

int main()
{
    int n = 1000;
    clock_t start, end;

    start = clock();
    johnsonTrotter(n);
    end = clock();

    printf("Clock: %lf", (end - start) / CLK_TCK);
    return 0;
}
