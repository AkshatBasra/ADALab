#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heap(int H[], int n) {
    int len = (n - 1) / 2;
    for (int i = len; i >= 0; i--) {
        int k = i, v = H[k];
        int heap = 0;
        while (k * 2 + 1 < n && !heap) {
            int j = k * 2 + 1;
            if (j + 1 < n && H[j] < H[j + 1])
                j++;
            if (v >= H[j])
                heap = 1;
            else {
                H[k] = H[j];
                k = j;
            }
        }
        H[k] = v;
    }
}


void heapsort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        heap(arr, n - i);
        swap(&arr[0], &arr[n - i - 1]);
    }
}

int main() {
    printf("Heapsort Algorithm\n");
    int arr[] = {10, 2, 5, 4, 1, 9, 7, 3, 8, 6};
    heapsort(arr, 10);
    for (int i = 0; i < 10; i++) {
        printf("%d\t", arr[i]);
    }
    return 0;
}
