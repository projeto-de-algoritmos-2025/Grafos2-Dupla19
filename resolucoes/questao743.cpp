#include <vector>
#include <unordered_map>
#include <queue>
#include <limits>

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

        // armazena o tempo minimo para cada no
        vector<int> dist(n + 1, numeric_limits<int>::max());
        dist[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        vector<long long> dist = dijkstra(n, adj, k);

        return 0;
    }
};