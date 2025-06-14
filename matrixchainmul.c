#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

void mcm(int *arr, int n, int **m, int **s)
{
    int i, l, j, k, q;
    for (i = 0; i < n; i++)
    {
        m[i] = (int *)calloc(n, sizeof(int));
        s[i] = (int *)calloc(n, sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        m[i][i] = 0;
    }
    for (l = 2; l <= n; l++)
    {
        for (i = 0; i < n - l + 1; i++)
        {
            j = i + l - 1;
            m[i][j] = INT_MAX;

            for (k = i; k < j; k++)
            {
                q = m[i][k] + m[k + 1][j] + (arr[i] * arr[k + 1] * arr[j + 1]);

                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void printsol(int **s, int i, int j)
{
    if (i == j)
    {
        printf("A%d ", i + 1);
    }
    else
    {
        printf("(");
        printsol(s, i, s[i][j]);
        printf("*");
        printsol(s, s[i][j] + 1, j);
        printf(")");
    }
}

int main()
{
    int n, i, j;
    printf("Enter number of matrix : ");
    scanf("%d", &n);

    int *arr = (int *)malloc((n + 1) * sizeof(int));
    printf("Enter Data : ");
    for (i = 0; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int **m = (int **)malloc(n * sizeof(int *));
    int **s = (int **)malloc(n * sizeof(int *));

    clock_t start = clock();
    mcm(arr, n, m, s);
    clock_t end = clock();

    printf("Table m[i][j] (minimum multiplication costs):\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
    printf("\nTable s[i][j] (split points):\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", s[i][j]);
        }
        printf("\n");
    }

    printsol(s, 0, n - 1);
    double timetaken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time = %lf s\n", timetaken);
    return 0;
}