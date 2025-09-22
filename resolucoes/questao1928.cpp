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
 }
};