#include<iostream>
#include<vector>
using namespace std;

void DFS(vector<vector<int>>graph, int start)
{
 int n=graph.size();
 vector<int> stack(n);
 vector<int> visited(n,0);
 int top=0;
 stack[top]=start;
 visited[start]=1;
 while(top>=0)
 {
  int current=stack[top--];
  cout<<current<<" ";
  for(int i=n-1;i>=0;i--)
  {
   if(graph[current][i] && !visited[i])
   {
    visited[i]=1;
    stack[++top]=i;
   }
  }
 }
}

int main()
{
 int n;
 cout<<"Enter the no. of vertices: ";
 cin>>n;
 int more=1;
 int u,v;
 vector<vector<int>> graph(n,vector<int>(n,0));
 cout<<"Enter the u, then v: \n";
 while(more)
 {
  cin>>u>>v;
  if(u>=0 && u<n && v>=0 && v<n)
  {
   graph[u][v]=1;
   cout<<"Want to add more edge(enter 0 for No and 1 for Yes): ";
   cin>>more;
  }
  else
  {
    cout<<"Please enter valid edge:\n";
  }
 
 
 }
 int start;
 cout<<"Enter the starting vertex: ";
 cin>>start;
 DFS(graph,start);

 return 0;
}
