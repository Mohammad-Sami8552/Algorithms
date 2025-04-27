#include<iostream> 
using namespace std;
 void swap(int &a, int &b)
{
  int temp=a;
  a=b;
  b=temp;
}

void heapify(int *arr, int n,int i)
{
 int largest=i;
 int l=i*2+1;
 int r=i*2+2;
 if(l<n && arr[largest]<arr[l])
 largest=l;
 if(r<n && arr[largest]<arr[r])
 largest=r;
 if(largest!=i)
 {
 swap(arr[largest],arr[i]);
 heapify(arr, n,largest);
 }
 
}
void heapSort(int *arr, int n)
{
 for(int i=n/2-1;i>=0;i--)
  heapify(arr,n,i); 
 for(int i=n-1;i>=0;i--)
 {
  swap(arr[0],arr[i]);
  heapify(arr,i,0);
 }

}
int main()
{
 int n;
 cout<<"Enter the no. of elements in the list: ";
 cin>>n;
 int arr[n];
 cout<<"Now enter the elements of the list: ";
 for(int i=0;i<n;i++)
 {
  cin>>arr[i]; 
 }
 heapSort(arr,n);
 cout<<"\nThe final sorted list is as follows:-\n";
 for(int i=0;i<n;i++)
 {
  cout<<arr[i]<<" "; 
 }
 return 0;
}
