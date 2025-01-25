#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;

    printf("enter the size of array: ");
    scanf("%d", &n);
    int *arr;
    arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements of array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", (arr + i));
    }
    for (int i = 0; i < n; i++)
    {
        int idx = i;
        int min = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            if (min > arr[j])
            {
                min = arr[j];
                idx = j;
            }
        }
        arr[idx] = arr[i];
        arr[i] = min;
    }
    printf("The sorted array is as follows:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
    free(arr);
    return 0;
}