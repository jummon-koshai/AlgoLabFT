#include <bits/stdc++.h>
using namespace std;

void bellmanFord(int V, vector<vector<int>> &edges, int src)
{
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++)
    {
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        if (dist[u] != INT_MAX && dist[u] + w < dist[v])
        {
            cout << "Graph contains negative weight cycle\n";
            return;
        }
    }

    cout << "Vertex \tDistance from Source\n";
    for (int i = 0; i < V; i++)
    {
        cout << i << "\t" << dist[i] << "\n";
    }
}

int main()
{
    int V = 5;
    vector<vector<int>> edges =
    {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };
    int src = 0;
    cout << "Bellman-Ford Shortest Path from Source " << src << ":\n";
    bellmanFord(V, edges, src);
    return 0;
}
