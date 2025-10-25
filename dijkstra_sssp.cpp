#include <bits/stdc++.h>
using namespace std;

int minDistance(vector<int> &dist, vector<bool> &visited, int V)
{
    int minVal = INT_MAX, minIndex;
    for (int v = 0; v < V; v++)
    {
        if (!visited[v] && dist[v] <= minVal)
        {
            minVal = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void dijkstra(vector<vector<int>> &graph, int src)
{
    int V = graph.size();
    vector<int> dist(V, INT_MAX);
    vector<bool> visited(V, false);

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, visited, V);
        visited[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
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
    vector<vector<int>> graph =
    {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };
    int src = 0;
    cout << "Dijkstra's Shortest Path from Source " << src << ":\n";
    dijkstra(graph, src);
    return 0;
}
