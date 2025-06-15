#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define W 0
#define G 1
#define B 2

int dfstime = 0;

void dfsvisit(int **arr, int V, int *color, int *f, int *pi, int *d, int u)
{
    printf("%d ", u);
    dfstime++;
    d[u] = dfstime;
    color[u] = G;

    int v;
    for (v = 0; v < V; v++)
    {
        if (arr[u][v] && color[v] == W)
        {
            pi[v] = u;
            dfsvisit(arr, V, color, f, pi, d, v);
        }
    }

    color[u] = B;
    dfstime++;
    f[u] = dfstime;
}

void dfs(int **arr, int V)
{
    int *color = (int *)malloc(V * sizeof(int));
    int *f = (int *)calloc(V, sizeof(int));
    int *d = (int *)calloc(V, sizeof(int));
    int *pi = (int *)malloc(V * sizeof(int));

    int i;

    for (i = 0; i < V; i++)
    {
        color[i] = W;
        pi[i] = -1;
    }
    dfstime = 0;

    for (i = 0; i < V; i++)
    {
        if (color[i] == W)
        {
            dfsvisit(arr, V, color, f, pi, d, i);
        }
    }

    printf("\nVertex\tDiscovery\tFinish\tParent\n");
    for (i = 0; i < V; i++)
    {
        printf("%d\t%d\t\t%d\t%d\n", i, d[i], f[i], pi[i]);
    }
}

int main()
{
    int V, i, E = 0, j;
    printf("Enter number of vertex : ");
    scanf("%d", &V);

    int **arr = (int **)malloc(V * sizeof(int *));
    printf("Enter graph : \n");

    for (i = 0; i < V; i++)
    {
        arr[i] = (int *)malloc(V * sizeof(int));
        for (j = 0; j < V; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    clock_t s = clock();
    dfs(arr, V);
    clock_t e = clock();
    double tt = ((double)(e - s)) / CLOCKS_PER_SEC;
    printf("time taken : %lf s\n", tt);
    return 0;
}

// 0 0 1 1 0 0 0
// 0 0 0 1 0 1 0
// 0 0 0 0 0 0 1
// 0 1 0 0 1 0 1
// 0 0 0 1 0 0 1
// 0 1 0 0 0 0 1
// 0 0 0 1 1 1 0
