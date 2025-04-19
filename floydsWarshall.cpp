#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int min(int x, int y)
{
 return x<y?x:y;
}

void floydsWarshall(vector<vector<int>>&SPC)
{
 int n=SPC.size();
 for(int k=0;k<n;k++)
 {
  for(int i=0;i<n;i++)
  {
   for(int j=0;j<n;j++)
   {
    if(i!=j && SPC[i][k]!=INT_MAX && SPC[k][j]!=INT_MAX)
     SPC[i][j]=min(SPC[i][j],SPC[i][k]+SPC[k][j]);
   }
  }
  
 }
}

int main()
{
 int n;
 cout<<"Enter the no. of vertices: ";
 cin>>n;
 vector<vector<int>>graph(n, vector<int>(n,INT_MAX));
 int u,v,wt;
 int more=1;
 while(more)
 {
  cout<<"Enter first u, v(u->v), then its weight:\n";
  cin>>u>>v>>wt;
  graph[u][v]=wt;
  cout<<"Want to add more edge (enter 0 for No and 1 for Yes): ";
  cin>>more;
 }
 for(int i=0;i<n;i++)
 {
  graph[i][i]=0;
 }
 floydsWarshall(graph);
 cout<<"The final SPC matrix of the graph is as follows: \n";
 for(int i=0;i<n;i++)
 {
  for(int j=0;j<n;j++)
  {
   cout<<graph[i][j]<<" ";
  }
  cout<<endl;
 }
 return 0;

}
 
