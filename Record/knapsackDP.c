#include <stdio.h>

struct Item
{
    int weight, value;
};

int memoryFunction(int i, int j, struct Item list[])
{
    if(i == 0 || j == 0)
        return 0;
    if(j < list[i].weight)
        return memoryFunction(i - 1, j, list);
    else
    {
        int v1 = memoryFunction(i - 1, j, list);
        int v2 = memoryFunction(i - 1, j - list[i].weight, list) + list[i].value;
        if(v1 > v2)
        {
            return v1;
        }

        return v2;
    }
}

int main()
{
    int n, capacity;
    printf("Enter Number of Items: ");
    scanf("%d", &n);
    printf("Enter Total Capacity: ");
    scanf("%d", &capacity);

    struct Item list[n];
    printf("Enter Weight and Value of Items:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d%d", &list[i].weight, &list[i].value);
    }
    int val = memoryFunction(n, capacity, list);
    printf("Value of Knapsack: %d", val);
    return 0;
}
