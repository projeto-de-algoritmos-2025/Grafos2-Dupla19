#include <vector>
#include <queue>
#include <limits>
#include <iostream>

using namespace std;

const long long INF = numeric_limits<long long>::max();

vector<long long> dijkstra(int n, const vector<vector<pair<int, int>>> &graph, int start)
{
    vector<long long> dist(n, INF);
    dist[start] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, start});

    while (!pq.empty())
    {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u])
        {
            continue;
        }

        for (const auto &edge : graph[u])
        {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] != INF && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

class Solution
{
public:
    long long minimumWeight(int n, vector<vector<int>> &edges, int src1, int src2, int dest)
    {
        // Constrói os grafos: original e reverso
        vector<vector<pair<int, int>>> adj(n), rev_adj(n);
        for (const auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            rev_adj[v].push_back({u, w}); // Aresta reversa
        }

        // Vamos parar por aqui. A próxima etapa será rodar Dijkstra.
        // A lógica de execução e a iteração final serão nos próximos commits.
        return 0; // Valor temporário
    }
};