#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int minIndex(vector<int>&key, vector<bool>&mst)
{
 int V=mst.size();
 int min=INT_MAX,min_idx;
 for(int v=0;v<V;v++)
 {
  if(!mst[v] && key[v]<min)
  {
    min=key[v];
    min_idx=v;
  }
 }
 return min_idx;
 
} 

int printMST(vector<int>&parent,vector<vector<int>>&graph)
{
 int V=graph.size();
 int sum=0;
 cout<<"Edge  "<<"Weight"<<endl;
 for(int i=1;i<V;i++)
 {
   cout<<parent[i]<<"->"<<i<<"   "<<graph[parent[i]][i]<<endl;
   sum+=graph[parent[i]][i];
 }
 return sum;
}

void primMST(vector<vector<int>>&graph,int src)
{
 int V=graph.size();
 vector<int> key(V,INT_MAX);
 vector<bool>mst(V,false);
 vector<int>parent(V);
 key[src]=0;
 parent[src]=-1;
 for(int count=0;count<V-1;count++)
 {
  int u=minIndex(key,mst);
  mst[u]=true;
  for(int v=0;v<V;v++)
  {
   if(graph[u][v] && !mst[v] && graph[u][v]<key[v])
   {
     key[v]=graph[u][v];
     parent[v]=u;
   }
  }
 }
 int min_weight=printMST(parent,graph);
 cout<<"The minimum weight of spanning tree is "<<min_weight<<endl;
}

int main()
{
 vector<vector<int>>graph=
                                { { 0, 2, 0, 6, 0 },
                                { 2, 0, 3, 8, 5 },
                                { 0, 3, 0, 0, 7 },
                                { 6, 8, 0, 0, 9 },
                                { 0, 5, 7, 9, 0 } };
 primMST(graph,0);
 return 0;
}
