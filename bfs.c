#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define W 0
#define G 1
#define B 2
#define INF INT_MAX

typedef struct
{
    int *arr;
    int front, rear, size;
} Queue;

void initializequeue(Queue *q, int s)
{
    q->size = s;
    q->arr = (int *)malloc(s * sizeof(int));
    q->front = -1;
    q->rear = -1;
}

void enqueue(Queue *q, int val)
{
    if ((q->rear + 1) % q->size == q->front)
    {
        printf("Queue overflowed\n");
        return;
    }
    if (q->front == -1)
    {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % q->size;
    q->arr[q->rear] = val;
}

int dequeue(Queue *q)
{
    if (q->front == -1)
    {
        printf("Queue underflow\n");
        return INF;
    }

    int val = q->arr[q->front];
    if (q->front == q->rear)
    {
        q->front = q->rear = -1; // Queue is empty
    }
    else
    {
        q->front = (q->front + 1) % q->size;
    }
    return val;
}

int isEmpty(Queue *q)
{
    return q->front == -1 && q->rear == -1 ? 1 : 0;
}
void bfs(int **arr, int V, int s)
{
    Queue q;
    initializequeue(&q, V);

    int *color = (int *)malloc(V * sizeof(int));
    int *d = (int *)calloc(V, sizeof(int));
    int *pi = (int *)malloc(V * sizeof(int));

    int i, u, v;

    for (i = 0; i < V; i++)
    {
        color[i] = W;
        d[i] = INF;
        pi[i] = -1;
    }

    color[s] = G;
    d[s] = 0;
    pi[s] = -1;

    enqueue(&q, s);
    printf("BFS traversal = ");

    while (!isEmpty(&q))
    {
        u = dequeue(&q);
        printf("%d ", u);

        for (v = 0; v < V; v++)
        {
            if (arr[u][v] && color[v] == W)
            {
                color[v] = G;
                d[v] = d[u] + 1;
                pi[v] = u;
                enqueue(&q, v);
            }
        }
        color[u] = B;
    }
    printf("\n");
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
    int src;
    printf("Enter source : ");
    scanf("%d", &src);

    clock_t s = clock();
    bfs(arr, V, src);
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