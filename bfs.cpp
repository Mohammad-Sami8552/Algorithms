#include<bits/stdc++.h>
using namespace std;

void BFS(vector<vector<int>> &graph, int start)
{
 int n=graph.size();
 int queue[n];
 int front=0,rear=0;
 queue[rear]=start;
 vector<int>visited(n,0);
 visited[start]=1;
 while(front<=rear )
 {
  int current=queue[front++];
  cout<<current<<" ";
  for(int i=0;i<n;i++)
  {
   if(graph[current][i] && !visited[i])
   {
    visited[i]=1;
    queue[++rear]=i;
   }
  }
 } 
}

int main()
{
 int n;
 cout<<"Enter the no. of vertices: ";
 cin>>n;
 vector<vector<int>>graph(n,vector<int>(n,0));
 int u,v;
 int more=1;
 while(more)
 {
  cout<< "Enter the u and v between which you want to connect an edge:\n";
  cin>>u>>v;
  graph[u][v]=1;
  cout<<"Want to add more edge(enter 0 for No and 1 for Yes): ";
  cin>>more;
 }
 int start;
 cout<<"Enter the starting vertex of BFS traversal: ";
 cin>>start;
cout<<"The BFS traversal is as follows: ";
 BFS(graph,start);

 return 0;
}