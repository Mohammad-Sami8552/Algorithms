#include <iostream>
using namespace std;
void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
int partition(int arr[], int low, int high)
{
    int i = low - 1;
    int pivot = arr[high];
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
void qkSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        qkSort(arr, low, pi - 1);
        qkSort(arr, pi + 1, high);
    }
}
int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "The array elements before sorting is as follolws:\n";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }

    qkSort(arr, 0, n - 1);
    
    cout << "\nThe array elements after sorting is as follolws:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }

    return 0;
}

