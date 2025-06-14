#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define INF INT_MAX

typedef struct
{
    int u;
    int v;
    int wt;
} Edge;

void bellmanFord(Edge *arr, int V, int E, int src)
{
    int *dist = (int *)malloc(V * sizeof(int));
    int i, j, u, v, wt;

    for (i = 0; i < V; i++)
    {
        dist[i] = INF;
    }

    for (i = 1; i <= V - 1; i++)
    {
        for (j = 0; j < E; j++)
        {
            u = arr[j].u;
            v = arr[j].v;
            wt = arr[j].wt;

            if (dist[u] != INF && dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }
    for (j = 0; j < E; j++)
    {
        u = arr[j].u;
        v = arr[j].v;
        wt = arr[j].wt;

        if (dist[u] != INF && dist[u] + wt < dist[v])
        {
            printf("Negative cycle detected\n");
            return;
        }
    }

    printf("Vertex distance from Source %d :\n", src);
    printf("Destination\t\tDistance\n");
    for (i = 0; i < V; i++)
    {
        if (dist[i] == INF)
        {
            printf("%11d\t\tINF\t\n", i);
        }
        else
        {
            printf("%11d\t\t%-8d\t\n", i, dist[i]);
        }
    }
}

int main()
{
    int V, i, E = 0, j;
    printf("Enter number of vertex : ");
    scanf("%d", &V);

    int **arr = (int **)malloc(V * sizeof(int *));
    print("Enter graph : ");

    for (i = 0; i < V; i++)
    {
        arr[i] = (int *)malloc(V * sizeof(int));
        for (j = 0; j < V; j++)
        {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] != 0)
            {
                E++;
            }
        }
    }

    Edge *edge = (Edge *)malloc(E * sizeof(Edge));
    int k = 0, source;

    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            if (arr[i][j] != 0)
            {
                edge[k].u = i;
                edge[k].v = j;
                edge[k].wt = arr[i][j];
            }
        }
    }

    printf("enter source : ");
    scanf("%d", &source);
    clock_t s = clock();
    bellmanford(edge, V, E, source);
    clock_t e = clock();
    double tt = ((double)(e - s)) / CLOCKS_PER_SEC;
    printf("Tiem taken : %lf s\n", tt);
    return 0;
}