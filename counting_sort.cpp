#include<bits/stdc++.h>
using namespace std;
//Finding maximum elements
int findMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

//counting sort
void countingSort(int arr[], int n, int max)
{
    int *arr_;
    int *output;
    output = (int *)malloc(n * sizeof(int));
    arr_ = (int *)malloc((max + 1) * sizeof(int));
    for (int i = 0; i < max + 1; i++)
    {
        arr_[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        arr_[arr[i]]++;
    }
    for (int i = 1; i < max + 1; i++)
    {
        arr_[i] += arr_[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        output[--arr_[arr[i]]] = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
    free(output);
    free(arr_);
}

int main()
{
    int *arr, n;
    cout<<"Enter the size of an array: ";
    cin>>n;
    arr = (int *)malloc(n * sizeof(int));
    cout<<"Enter the elements of the array:\n";
    for (int i = 0; i < n; i++)
    {
       cin>>arr[i];
    }
    int max = findMax(arr, n);
    countingSort(arr, n, max);
     cout<<"The sorted array is as follows:\n";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<"\t";
    }
    free(arr);
    return 0;
}