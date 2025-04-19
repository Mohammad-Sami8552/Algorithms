#include<bits/stdc++.h>
using namespace std;

float fractionalKnapsack(vector<vector<float>>&items,int W)
{
 int n=items.size();
 for(int i=0;i<n;i++)
 {
  float tempc=items[i][1];
  float tempr=items[i][2];
  float tempw=items[i][0];
  int j=i-1;
  while(j>=0 && tempr>items[j][2])
  {
   items[j+1][2]=items[j][2];
   items[j+1][1]=items[j][1];
   items[j+1][0]=items[j][0];
   j--;
  }
  items[j+1][0]=tempw;
  items[j+1][1]=tempc;
  items[j+1][2]=tempr;
 }
 int i=0;
 float maxP=0.0;
 while(W!=0 && i<n)
 {
  if(W>=items[i][0])
  {
   W-=items[i][0];
   maxP+=items[i][1];
  }
  else
  {
  maxP+=items[i][1]*(float(W)/float(items[i][0]));
  W=0;
  }
  i++;
 }
 return maxP;
} 

int main()
{
 int W;
 cout<<"Enter the Knapsack Capacity: ";
 cin>>W;
 vector<vector<float>> items;
 int n;
 cout<<"Enter the no. of items: ";
 cin>>n;
 cout<<"Enter the weight, then its cost of items:\n";
 float w,cost;
 for(int i=0;i<n;i++)
 {
  cin>>w>>cost;

  items.push_back({w,cost,(float(cost)/float(w))});
 }
 float maxProfit=fractionalKnapsack(items,W);
 cout<<"The maximum profit is "<<maxProfit<<endl;
 return 0; 
}
