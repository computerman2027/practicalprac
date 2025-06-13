#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int binomial(int n,int k)
{
    if(k>n)
    return 0;
    if(k==n || k==0)
    return 1;
    return binomial(n-1,k-1)+binomial(n-1,k);
}

int main()
{
    int n,k;

    printf("Enter n : ");
    scanf("%d",&n);

    printf("Enter k : ");
    scanf("%d",&k);

    clock_t start =clock();
    int ans=binomial(n,k);
    clock_t end =clock();

    double timetaken=((double)(end-start))/CLOCKS_PER_SEC;

    printf("ans = %d\n",ans);
    printf("Time = %lf s\n",timetaken);
    
    return 0;
}