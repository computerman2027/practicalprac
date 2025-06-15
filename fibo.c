#include<stdio.h>
#include<stdlib.h>

void fibo1(int n)
{
    int i;
    int* dp = (int*)malloc((n)*sizeof(int));
    for(i=0;i<n;i++)
    {
        if(i==0 || i==1)
        {
            dp[i]=1;
        }
        else
        dp[i]=dp[i-1]+dp[i-2];
    }

    printf("Ans = %d\n",dp[n-1]);
}

int fibo2(int n)
{
    if(n<=1)
    {
        return 1;
    }
    return fibo2(n-1)+fibo2(n-2);
}

int main()
{
    printf("Enter n : ");

    int n;
    scanf("%d",&n);
    int ans1 = fibo2(n);
    int ans2 = fibo2(n);

    printf("Ans 1 = %d\n",ans1);
    printf("Ans 2 = %d\n",ans2);

    return 0;
}