#include <stdio.h>
#include <limits.h>
#include <time.h>

void dijkstra(int n, int graph[n][n], int start)
{
    int d[n], vis[n];
    for(int i = 0; i < n; i++)
    {
        d[i] = INT_MAX;
        vis[i] = 0;
    }
    d[start] = 0;
    for(int count = 0; count < n - 1; count++)
    {
        int min = INT_MAX, u;
        for(int v = 0; v < n; v++)
        {
            if(!vis[v] && d[v] <= min)
            {
                min = d[v];
                u = v;
            }
        }
        if(u == -1) break; // No reachable vertex left
        vis[u] = 1;
        for(int v = 0; v < n; v++)
        {
            if(!vis[v] && d[u] + graph[u][v] < d[v] && graph[u][v] != INT_MAX)
            {
                d[v] = d[u] + graph[u][v];
            }
        }
    }
    printf("Vertex\tDistance\n");
    for(int i = 0; i < n; i++)
    {
        if(d[i] == INT_MAX)
            printf("%d\tINF\n", i);
        else
            printf("%d\t%d\n", i, d[i]);
    }
}

int main()
{
    int n = 5, start = 0;
    // int graph[n][n];
    int graph[5][5] =
                     {
                         {0, 4, 3, 0, 0},
                         {2, 0, 6, 0, 3},
                         {0, 10, 0, 4, 0},
                         {0, 0, 3, 0, 1},
                         {0, 0, 2, 5, 0}
                     };

    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = 0; j < n; j++)
    //     {
    //         scanf("%d", &graph[i][j]);
    //     }
    // }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i != j && graph[i][j] == 0)
            {
                graph[i][j] = INT_MAX;
            }
        }
    }
    // clock_t start1, end;
    // start1 = clock();
    dijkstra(n, graph, start);
    // end = clock();
    // printf("Clock: %lf", (end - start1) / CLK_TCK);
    return 0;
}
