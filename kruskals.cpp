#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class DSU
{
 vector<int>rank,parent;
 public:
  DSU(int n){
   parent.resize(n);
   rank.resize(n,1);
   for(int i=0;i<n;i++)
   {
    parent[i]=i;
   }
  }

  int find(int i)
  {
   return (i==parent[i])?i: (parent[i]=find(parent[i]));
  }
  void unite(int x, int y)
  {
   int s1=find(x);
   int s2=find(y);
   if(rank[s1]<rank[s2]) parent[s1]=s2;
   else if(rank[s1]>rank[s2]) parent[s2]=s1;
   else
   {
    parent[s2]=s1; rank[s1]++;
   }
  }
};

int kruskalsMST(int V, vector<vector<int>>&edges)
{
 sort(edges.begin(),edges.end(),[](vector<int>&a, vector<int>&b){ return a[2]<b[2];});
 int cost=0;
 int count=0;
 DSU dsu(V);
 cout<<"The edges of MST is as follows:\n";
 for(auto &e: edges)
 {
  int x=e[0];
  int y=e[1];
  int w=e[2];
  if(dsu.find(x)!=dsu.find(y))
  {
    dsu.unite(x,y);
    cost+=w;
    cout<<x<<" -> "<<y<<w<<endl;
    if(++count==V-1)
     break;
    
  }
   
 }
 return cost; 
}

int main()
{
 int V;
 cout<<"Enter the no. of vertices: ";
 cin>>V;
 vector<vector<int>>edges;
 int more=1;
 int u, v, wt;
 cout<<"Enter the u ->v, then its weight:\n";
 while(more)
 {
  cin>>u>>v>>wt;
  if(u>=0 && u<V && v>=0 && v<V )
  {
   edges.push_back({u,v,wt});
   cout<<"Want to add more edges( 0 for No and 1 for Yes): ";
   cin>>more;
   if(more)
     cout<<"Enter the u ->v, then its weight:\n"; 
  }
  else
   cout<<"Please enter the valid vertices: ";

 }
  int min_weight=kruskalsMST(V, edges);
  cout<<"The minimum spanning tree weight is :"<<min_weight<<endl;
 return 0;
}
  

  