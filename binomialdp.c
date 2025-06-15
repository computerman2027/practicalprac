#include <stdio.h>
#include <stdlib.h>

int **dp;
int size = -1;

void solve(int n, int k)
{
    int i, j;
    dp = (int **)malloc((n + 1) * sizeof(int *));
    for (i = 0; i <= n; i++)
    {
        dp[i] = (int *)malloc((k + 1) * sizeof(int));
    }

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
    }

    printf("Bionomial table : \n");

    for(i = 0; i <= n; i++)
    {
        for (j = 0; j <= i; j++)
        {
            printf("%d\t",dp[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n, k;

    printf("Enter n : ");
    scanf("%d", &n);
    printf("Enter k : ");
    scanf("%d", &k);

    solve(n, k);

    printf("Ans = %d", dp[n][k]);

    return 0;
}