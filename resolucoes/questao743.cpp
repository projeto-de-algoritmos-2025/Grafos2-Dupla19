#include <vector>
#include <unordered_map>
#include <queue>
#include <limits>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (const auto& time : times) {
            int u = time[0];
            int v = time[1];
            int w = time[2];
            adj[u].push_back({v, w});
        }

        //armazena o tempo minimo para cada no
        vector<int> dist(n + 1, numeric_limits<int>::max());
        dist[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        
        
        return 0;
    }
};