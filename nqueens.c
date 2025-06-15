#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int issafe(int* board, int row, int col)
{
    int i;
    for(i=0;i<row;i++)
    {
        if(board[i]==col 
        || board[i]-i==col - row
        || board[i]+i==col+row)
        {
            return 0;
        }
    }
    return 1;
}

void solve(int* board, int row, int n, int* sol)
{
    int i,col;
    if(row==n)
    {
        (*sol)++;
        printf("Solution vector %d : ",*sol);
        for(i=0;i<n;i++)
        {
            printf("%d ",board[i]+1);
        }
        printf("\n");
        return;
    }

    for(col=0;col<n;col++)
    {
        if(issafe(board,row,col))
        {
            board[row]=col;
            solve(board,row+1,n,sol);
        }
    }
}

int main()
{
    int n;

    printf("Enter number of queens : ");
    scanf("%d",&n);

    int* board=(int*)malloc(n*sizeof(int));

    int sols=0;

    solve(board,0,n,&sols);

    printf("No of solutions : %d\n",sols);

    return 0;
}