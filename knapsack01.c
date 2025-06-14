#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int Max(int a, int b) {
    return (a > b) ? a : b;
}

int* knapsack(int** arr,int n,int maxwt)
{
    int** dp = (int**)malloc((n+1)*sizeof(int*));
    int i,j;
    for(i=0;i<=n;i++)
    {
        dp[i]=(int*)calloc(maxwt+1,sizeof(int));
    }

    for(i=0;i<=n;i++)
    {
        for(j=0;j<=maxwt;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
            else
            {
                if(j-arr[i-1][1]>=0)
                {
                    dp[i][j]=Max(dp[i-1][j],arr[i-1][0]+dp[i-1][j-arr[i-1][1]]);
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }   
    }

    for(i=0;i<=n;i++)
    {
        for(j=0;j<=maxwt;j++)
        {
            printf("%d\t",dp[i][j]);
        }
        printf("\n");
    }
    int* ans = (int*)calloc((n+1),sizeof(int));
    i=n;
    j=maxwt;
    int profit = 0;
    while(i>0 && j>0)
    {
        if(dp[i][j]==dp[i-1][j])
        {
            i=i-1;
        }
        else
        {
            ans[i-1]=1;
            profit+=arr[i-1][0];
            j=j-arr[i-1][1];
        }
    }
    ans[n]=profit;
    return ans;
}
//0 - profit
//1 - weight
int main()
{
    int n,i;
    int maxwt;
    printf("Enter number of weights : ");
    scanf("%d",&n);

    int** arr=(int**)malloc(n*sizeof(int*));
    for(i=0;i<n;i++)
    {
        arr[i]=(int*)malloc(2*sizeof(int));
        printf("Enter profit : ");
        scanf("%d",&arr[i][0]);
        printf("Enter weight : ");
        scanf("%d",&arr[i][1]);
    }

    printf("Enter max weight of bag : ");
    scanf("%d",&maxwt);

    clock_t start = clock();
    int *ans = knapsack(arr,n,maxwt);
    clock_t end = clock();

    double timetaken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Answer vector : ");
    for(i=0;i<n;i++)
    {
        printf("%d ",ans[i]);
    }
    printf("\n");
    printf("Profit = %d\n",ans[n]);

    printf("Time = %lf s\n", timetaken);
    return 0;
}