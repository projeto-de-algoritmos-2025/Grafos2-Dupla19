class Solution { 
public: 
 int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        // Construir o grafo: city -> list of (neighbor, time)
        vector<vector<pair<int,int>>> graph(n);
        for (auto &e : edges) {
            int u = e[0], v = e[1], t = e[2];
            graph[u].push_back({v, t});
            graph[v].push_back({u, t});
        }
        
        // Estrutura para prioridade pelo custo mínimo
        struct State {
            int city;
            int time;
            int cost;
            bool operator>(const State &other) const {
                return cost > other.cost;
            }
        }

    priority_queue<State, vector<State>, greater<State>> pq;
    vector<vector<int>> minTime(n, vector<int>(maxTime + 1, INT_MAX));
            
    pq.push({0, 0, passingFees[0]});
            minTime[0][0] = passingFees[0];
            
            while (!pq.empty()) {
                auto cur = pq.top(); pq.pop();
                int u = cur.city, t = cur.time, c = cur.cost;
                
                if (u == n - 1) return c; // Chegou no destino
                
                for (auto &[v, timeNeeded] : graph[u]) {
                    int newTime = t + timeNeeded;
                    int newCost = c + passingFees[v];
                    
                    if (newTime <= maxTime && newCost < minTime[v][newTime]) {
                        minTime[v][newTime] = newCost;
                        pq.push({v, newTime, newCost});
                    }
                }
            }
    }
};