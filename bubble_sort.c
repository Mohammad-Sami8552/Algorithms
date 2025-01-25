#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;

    printf("enter the size of array: ");
    scanf("%d",&n);
    int *arr;
    arr=(int *)malloc(n*sizeof(int));
    printf("Enter the elements of array:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",(arr+i));
    }
    // bubble sort
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp;
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("The sorted array via bubble sort is as follows\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);
    }
    free(arr);
    return 0;
}

