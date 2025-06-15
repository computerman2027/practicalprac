#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define INF INT_MAX

void printmat(int** arr, int n, int k)
{
    printf("D%d = \n",k);
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(arr[i][j]==INF)
            {
                printf("%7s\t","INF");
            }
            else
            printf("%7d\t",arr[i][j]);
        }
        printf("\n");
    }
}

void floydwarshall(int** arr, int V)
{
    int** d;
    int i,j,k=0,k2=0;

    d=(int**)malloc(V*sizeof(int*));
    for(i=0;i<V;i++)
    {
        d[i]=(int*)malloc(V*sizeof(int));
        for(j=0;j<V;j++)
        {
            d[i][j]=arr[i][j];
        }
    }
    printmat(d,V,k2);
    k2++;
    for(k=0;k<V;k++)
    {
        for(i=0;i<V;i++)
        {
            for(j=0;j<V;j++)
            {
                if(d[i][k] !=INF && d[k][j]!=INF && d[i][k]+d[k][j]<d[i][j])
                {
                    d[i][j]=d[i][k]+d[k][j];
                }
            }
        }
        printmat(d,V,k2);
        k2++;
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
            if(arr[i][j]==0 && i!=j)
            {
                arr[i][j]=INF;
            }
        }
    }

    clock_t s = clock();
    floydwarshall(arr, V);
    clock_t e = clock();
    double tt = ((double)(e - s)) / CLOCKS_PER_SEC;
    printf("Tiem taken : %lf s\n", tt);
    return 0;
}