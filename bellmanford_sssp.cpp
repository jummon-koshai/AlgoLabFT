#include <iostream>
#include <vector>
using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src)
{
    vector<int> dist(V, 1e8);
    dist[src] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if (dist[u] != (int)1e8 && dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }
    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        if (dist[u] != (int)1e8 && dist[u] + wt < dist[v])
        {
            return { -1 };
        }
    }
    return dist;
}

int main()
{
    int V = 5;
    vector<vector<int>> edges =
    {
        {0, 1, -1},
        {0, 2, 2},
        {1, 2, 1},
        {2, 3, 4},
        {3, 1, -3},
        {2, 4, 3},
        {4, 3, 3}
    };
    int src = 0;
    vector<int> ans = bellmanFord(V, edges, src);
    if (ans.size() == 1 && ans[0] == -1)
    {
        cout << "Negative cycle\n";
    }
    else
    {
        cout << "Vertex \t Distance from Source\n";
        for (int i = 0; i < ans.size(); i++)
        {
            cout << i << "\t\t\t" << ans[i] << "\n";
        }
    }
    return 0;
}
