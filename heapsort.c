#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b= temp;
}

void heapify(int* arr,int n,  int i)
{
    int l =(2*i)+1;
    int r =(2*i)+2;
    int largest = i;
    if(l<n && arr[l]>arr[largest])
    {
        largest=l;
    }
    if(r<n && arr[r]>arr[largest])
    {
        largest=r;
    }
    if(largest!=i)
    {
        swap(&arr[largest],&arr[i]);
        heapify(arr,n,largest);
    }
}
void buildmaxheap(int* arr, int n)
{
    int i;
    for(i=(n/2)-1;i>=0;i--)
    {
        heapify(arr,n,i);
    }
}

void heapsort(int* arr, int n)
{
    buildmaxheap(arr,n);
    int i;
    for(i=n-1;i>0;i--)
    {
        swap(&arr[0],&arr[i]);
        heapify(arr,i-1,0);
    }
}

int main()
{
    int n, i;
    printf("Enter size of array : ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter values : ");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("unsorted array : ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    clock_t start = clock();
    heapsort(arr, n);
    clock_t end = clock();

    double timetaken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("sorted array : ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("Time = %lf s\n", timetaken);
    return 0;
}