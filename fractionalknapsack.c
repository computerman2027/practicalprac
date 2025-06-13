#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int comp(const void* a, const void* b)
{
    double* x= *(double**)a;
    double* y= *(double**)b;
    if(x[2]<y[2])
    return 1;
    else
    return 0;
}

// 0 - profit 
// 1 - weight
// 2 - profit per weight
// 3 - index
double* fknapsack(double** arr,int n, double mw)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        arr[i][2]=arr[i][0]/arr[i][1];
    }
    qsort(arr,n,sizeof(arr[0]),comp);

    double* ans = (double*)calloc(n+1,sizeof(int));
    for(i=0;i<n && mw>0;i++)
    {
        if(mw/arr[i][1]>=1)
        {
            ans[(int)arr[i][3]]=1;
            mw-=arr[i][1];
            ans[n]+=arr[i][0];
        }
        else
        {
            ans[(int)arr[i][3]]=mw/arr[i][1];
            mw=0;
            ans[n]+=arr[i][0]*ans[(int)arr[i][3]];
        }   
    }
    return ans;
}

int main()
{
    int n,i;
    double maxwt;
    printf("Enter number of weights : ");
    scanf("%d",&n);

    double** arr=(double**)malloc(n*sizeof(double*));
    for(i=0;i<n;i++)
    {
        arr[i]=(double*)malloc(4*sizeof(double));
        printf("Enter profit : ");
        scanf("%lf",&arr[i][0]);
        printf("Enter weight : ");
        scanf("%lf",&arr[i][1]);
        arr[i][3]=i;
    }

    printf("Enter max weight of bag : ");
    scanf("%lf",&maxwt);

    clock_t start = clock();
    double *ans = fknapsack(arr,n,maxwt);
    clock_t end = clock();

    double timetaken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Answer vector : ");
    for(i=0;i<n;i++)
    {
        printf("%lf ",ans[i]);
    }
    printf("\n");
    printf("Profit = %lf\n",ans[n]);

    printf("Time = %lf s\n", timetaken);
    return 0;
}