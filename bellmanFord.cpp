#include <bits/stdc++.h>
using namespace std;
vector<int> bellmanford(int V, int src, vector<vector<int>> edges)
{
    vector<int> dist(V, 1e8);
    dist[src] = 0;
    for (int i = 0; i < V; i++)
    {
        for (vector<int> edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if (dist[u] != 1e8 && dist[u] + wt < dist[v])
            {
                if (i == V - 1)
                    return {-1};
                dist[v] = dist[u] + wt;
            }
        }
    }
    return dist;
}
int main()
{
    int V;
    int i=0;
    cout<<"Enter the no. of vertices: ";
    cin>>V;
    int src = 0;
    vector<vector<int>> ex;
    int more = 1;
    int u, v, wt;
    cout << "Enter the directed graph, first enter the two vertices then its weight:\n";
    while (more)
    {
        cin >> u >> v >> wt;
       ex.push_back({u,v,wt});
        cout << "Want to add more edges(0 for No and 1 for Yes): ";
        cin >> more;
    }

    vector<int> dist = bellmanford(V, src, ex);
    if (dist[0] == -1)
        cout << "The graph contains negative cycle, So here bellman ford algorithm fails";
    else
    {
        cout<<"The final shortest path from source vertex is as follows:\n";
        cout<<"Vertex |Distance(shortest)\n";
        for (auto x : dist)
        {
            cout << i << "      |"<<x<<endl;
            i++;
        }
    }

    return 0;
}