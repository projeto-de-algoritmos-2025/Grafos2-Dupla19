#include <vector>
#include <queue>
#include <limits>
#include <iostream>

using namespace std;

const long long INF = numeric_limits<long long>::max();

vector<long long> dijkstra(int n, const vector<vector<pair<int, int>>>& graph, int start) {
    vector<long long> dist(n, INF); //vetor para guardar a distancia de cada no
    dist[start] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        long long d = pq.top().first; //pega a menor distância na fila.
        int u = pq.top().second;      //pega o nó correspondente.
        pq.pop();

        if (d > dist[u]) {
            continue;
        }

        //itera sobre todos os vizinhos.
        for (const auto& edge : graph[u]) {
            int v = edge.first;     //vizinho
            int weight = edge.second; //custo
            
            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

class Solution {
public: 
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int, int>>> adj(n), rev_adj(n);

        // constroi o grafo e o grafo reverso
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            rev_adj[v].push_back({u, w});
        }

        vector<long long> dist1 = dijkstra(n, adj, src1);
        vector<long long> dist2 = dijkstra(n, adj, src2);
        vector<long long> dist_rev = dijkstra(n, rev_adj, dest);

        long long min_weight = INF;
        
        for (int i = 0; i < n; ++i) {
            if (dist1[i] != INF && dist2[i] != INF && dist_rev[i] != INF) {
                //calcula a soma do caminho a partir de cada nó.
                min_weight = min(min_weight, dist1[i] + dist2[i] + dist_rev[i]);
            }
        }
        
        if (min_weight == INF) {
            return -1;
        }
        
        return min_weight;
    }
};