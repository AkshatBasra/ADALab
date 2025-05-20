#include <limits.h>
#include <stdio.h>
#include <time.h>

int minKey(int key[], int mstSet[], int n)
{
    int min = INT_MAX, minIndex = -1;
    for (int i = 0; i < n; i++)
        if (!mstSet[i] && key[i] < min)
        {
            min = key[i];
            minIndex = i;
        }
    return minIndex;
}

void printMST(int n, int parent[], int graph[n][n])
{
    printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[parent[i]][i]);
}

void prim(int n, int graph[n][n], int parent[n])
{
    int key[n];
    int mstSet[n];
    for (int i = 0; i < n; i++)
    {
        key[i] = INT_MAX;  //infinity
        mstSet[i] = 0;     // Not included in MST
    }

    key[0] = 0;
    parent[0] = -1; // First node is always root of MST

    for (int count = 0; count < n - 1; count++)
    {
        int u = minKey(key, mstSet, n);
        mstSet[u] = 1;

        for (int i = 0; i < n; i++)
        {
            if (graph[u][i] && !mstSet[i] && graph[u][i] < key[i])
            {
                parent[i] = u;
                key[i] = graph[u][i];
            }
        }
    }
}

int main()
{
    int graph[5][5] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
    int mst[5];
    clock_t start, end;

    start = clock();
    prim(5, graph, mst);
    end = clock();

    printMST(5, mst, graph);
    printf("Clock: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}
