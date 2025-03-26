#include <bits/stdc++.h>
using namespace std;
int minimum(vector<int> dist, vector<bool> b)
{
  int min=INT_MAX;
  int min_idx=-1;
  for(int i=0;i<dist.size();i++)
  {
   if(dist[i]<min && !b[i])
   {
    min=dist[i];
    min_idx=i;
   }
  }
  return min_idx;
}

vector<int> dijkstrasAlgo(vector<vector<int>>&adj,int src)
{
    int V=adj.size();
    vector<int> dist(V,INT_MAX);
    vector<bool> b(V,false);
    dist[src]=0;
 
    for(int count=0;count<V-1;count++)
    {
      int u=minimum(dist,b);
      if(u==-1)break;
      b[u]=true;
      for(int v=0;v<V;v++)
      {
       if(dist[u]!=INT_MAX &&  adj[u][v] && !b[v] && dist[u]+adj[u][v]<dist[v])
       {
         dist[v]=dist[u]+adj[u][v];
       }
      }
    }
    return dist;
    
}
int main()
{
   int N;
   cout<<"Enter the no. of vertices: ";
   cin>>N;
    vector<vector<int>> adj(N,vector<int>(N,0));
    int wantGive=1;
    int u,v,wt;
    while(wantGive)
    {
       cout<<"Enter first u and v, then the edge weight: ";
       cin>>u>>v>>wt;
       adj[u][v]=wt;
       cout<<"Want to add more edges enter (0 for No and 1 for Yes)";
       cin>>wantGive;
    }
    int src;
    cout<<"Enter the source vertex: ";
    cin>>src;
    vector<int> result=dijkstrasAlgo(adj,src);
    cout<<"The distance of all the vertex from source vertex is as follows:\n";
    for(int i=0;i<N;i++)
    {
      cout<<i<< ": "<<result[i]<<endl;
    }
    return 0;
}