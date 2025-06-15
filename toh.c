#include<stdio.h>
#include<time.h>

void toh(int n,int start, int end, int via)
{
    if(n==1)
    {
        printf("Move disk 1 from %d to %d via %d\n",start,end,via);
        return;
    }
    toh(n-1,start,via,end);
    printf("Move disk %d from %d to %d via %d\n",n,start,end,via);
    toh(n-1,via,end,start);
}

int main()
{
    int n;
    printf("Enter no of disk : ");
    scanf("%d",&n);

    toh(n,1,3,2);

    return 0;
}