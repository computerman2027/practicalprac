#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define INF INT_MAX

int mindist(int* dist, int* visited, int V)
{
    int min=INF, mini;

    int i;

    for(i=0;i<V;i++)
    {
        if(!visited[i] && dist[i]<=min)
        {
            min=dist[i];
            mini=i;
        }
    }
    return mini;
}

void dikjtra(int** arr, int V,int src)
{
    int* dist=(int*)malloc(V*sizeof(int));
    int* visited=(int*)malloc(V*sizeof(int));

    int i,v,u;
    for(i=0;i<V;i++)
    {
        dist[i]=INF;
        visited[i]=0;
    }

    dist[src]=0;

    for(i=0;i<V-1;i++)
    {
        u=mindist(dist,visited,V);
        visited[u]=1;
        for(v=0;v<V;v++)
        {
            if(!visited[v] && arr[u][v] && dist[u]!=INF && dist[u]+arr[u][v]<dist[v])
            {
                dist[v]=dist[u]+arr[u][v];
            }
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
    printf("Enter graph : ");

    for (i = 0; i < V; i++)
    {
        arr[i] = (int *)malloc(V * sizeof(int));
        for (j = 0; j < V; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    int src;
    printf("Enter source : ");
    scanf("%d",&src);

    clock_t s = clock();
    dikjtra(arr, V,src);
    clock_t e = clock();
    double tt = ((double)(e - s)) / CLOCKS_PER_SEC;
    printf("time taken : %lf s\n", tt);
    return 0;
}