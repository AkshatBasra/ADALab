#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Item
{
    int weight, benefit, usedWeight;
    float value;
};

int maxValue(struct Item List[])
{
    float max = 0;
    int item;
    for(int i = 0; i < 5; i++)
    {
        if(List[i].value > max && List[i].weight > 0)
        {
            max = List[i].value;
            item = i;
        }
    }
    return item;
}

float knapsack(struct Item list[], int maxCapacity)
{
    for(int i = 0; i < 5; i++)
    {
        list[i].value = (float)list[i].benefit / list[i].weight;
        list[i].usedWeight = 0;
    }
    float netValue = 0;
    for(int i = 0; i < maxCapacity; i++)
    {
        int rem = maxValue(list);
        list[rem].weight--;
        list[rem].usedWeight++;
        netValue += list[rem].value;
    }
    printf("Item\tWeight\n");
    for(int i = 0; i < 5; i++)
    {
        printf("%d:\t%d\n", i+1, list[i].usedWeight);
    }
    printf("Value of Knapsack: %f", netValue);
    return netValue;
}

int main()
{
    struct Item list[5];
    srand(time(NULL));
    printf("Item\tBenefit\tWeight\n");
    for(int i = 0; i < 5; i++)
    {
        list[i].benefit = (rand() % 20) + 1;
        list[i].weight = (rand() % 10) + 1;
        printf(" %d:\t%d\t%d\n", i+1, list[i].benefit, list[i].weight);
    }
    int maxCapacity = 20;
    knapsack(list, maxCapacity);
    return 0;
}
