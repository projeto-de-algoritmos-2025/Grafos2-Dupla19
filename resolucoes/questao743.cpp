#include <vector>
#include <queue>
#include <limits>
#include <unordered_map>
#include <algorithm>

using namespace std;

const long long INF = numeric_limits<long long>::max();

// A função Dijkstra encapsulada
vector<long long> dijkstra(int n, const unordered_map<int, vector<pair<int, int>>> &graph, int start)
{
    vector<long long> dist(n + 1, INF);
    dist[start] = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, start});

    while (!pq.empty())
    {
        long long d = pq.top().first; // pega a menor distância na fila.
        int u = pq.top().second;      // pega o nó correspondente.
        pq.pop();

        if (d > dist[u])
        {
            continue;
        }

        // itera sobre todos os vizinhos.
        if (graph.count(u))
        {
            for (const auto &edge : graph.at(u))
            {
                int v = edge.first;
                int weight = edge.second;

                if (dist[u] + weight < dist[v])
                {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
    }
    return dist;
}

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        // constroi o grafo
        unordered_map<int, vector<pair<int, int>>> adj;
        for (const auto &time : times)
        {
            int u = time[0];
            int v = time[1];
            int w = time[2];
            adj[u].push_back({v, w});
        }

        //chama dijkstra e guarda as distâncias
        vector<long long> dist = dijkstra(n, adj, k);

        //encontra o maior tempo de chegada
        long long max_time = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (dist[i] == INF)
            {
                return -1;
            }
            max_time = max(max_time, dist[i]);
        }

        return static_cast<int>(max_time);
    }
};