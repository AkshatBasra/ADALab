#include <stdio.h>

int queue[10], fr = 0, re = -1;
void enqueue(int el)
{
    queue[++re] = el;
}
int dequeue()
{
    return(queue[fr++]);
}

void main()
{
    int adMatrix[4][4] = {
                            {0, 1, 1, 1},
                            {0, 0, 0, 1},
                            {0, 0, 0, 1},
                            {0, 0, 0, 0}
                        };
    int returnArr[4], vis[4] = {0}, indegree[4] = {0}, el, returnIndex = 0;
    for(int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if(adMatrix[i][j])
            {
                indegree[j]++;
            }
        }
    }
    for (int i = 0; i < 4; i++)
    {
        if (!indegree[i])
        {
            enqueue(i);
        }
    }
    while (fr <= re)
    {
        el = dequeue();
        vis[el] = 1;
        returnArr[returnIndex++] = el;
        for (int i = 0; i < 4; i++)
        {
            if (adMatrix[el][i] && !vis[i])
            {
                indegree[i]--;
                if(!indegree[i])
                {
                    enqueue(i);
                    //vis[i] = 1;
                }
            }
        }
    }
    printf("Topological Sorting\n");
    for (int i = 0; i < 4; i++)
    {
        printf("%d\t", returnArr[i]);
    }
}
