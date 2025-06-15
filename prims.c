#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct 
{
    int V;
    int** adj;
}Graph;

int minwt(int* wt, int* vis, int V)
{
    int min=INT_MAX;
    int minindex;
    int i;
    for(i=0;i<V;i++)
    {
        if(vis[i]==0 && wt[i]<min)
        {
            min=wt[i];
            minindex=i;
        }
    }
    return minindex;
}

void prims(Graph* G)
{
    int V= G->V;
    int* parent = (int*)malloc(V*sizeof(int));
    int* wt = (int*)malloc(V*sizeof(int));
    int* visited = (int*)calloc(V,sizeof(int));
    int i;

    for(i=0;i<V;i++)
    {
        parent[i]=-1;
        wt[i]=INT_MAX;
    }

    wt[0]=0;
    int e,v,u;

    for(e=0;e<V-1;e++)
    {
        u=minwt(wt,visited,V);
        visited[u]=1;
        for(v=0;v<V;v++)
        {
            if(G->adj[u][v] && visited[v]==0 && G->adj[u][v]<wt[v])
            {
                wt[v]=G->adj[u][v];
                parent[v]=u;
            }

        }
    }

    int sum=0;

    for(i=1;i<V;i++)
    {
        printf("%d -- %d == %d\n",parent[i],i,wt[i]);
        sum+=wt[i];
    }
    printf("\nMinimum Spanning Tree cost is: %d",sum);
}

int main()
{
    Graph *G=(Graph*)malloc(sizeof(Graph));

    printf("Enter number of vertices : ");
    scanf("%d",&G->V);

    printf("Enter Adj Mattrix : ");
    int i,j;
    G->adj=(int**)malloc(G->V*sizeof(int*));
    for(i=0;i<G->V;i++)
    {
        G->adj[i]=(int*) malloc(G->V*sizeof(int));
        for(j=0;j<G->V;j++)
        {
            scanf("%d",&G->adj[i][j]);
        
        }
    }

    prims(G);

    return 0;

}