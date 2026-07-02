// Last updated: 7/2/2026, 11:36:22 PM
class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& time) {
        vector<vector<array<int,2>>> graph(n);

        for(auto &e : edges){
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});   // Remove for directed graph
        }

        vector<int> dist(n, INT_MAX);

        priority_queue<array<int,2>, vector<array<int,2>>, greater<array<int,2>>> pq;
        // {distance, node}

        dist[0] = 0;
        pq.push({0, 0});

        while(!pq.empty()){

            auto [d, u] = pq.top();
            pq.pop();

            if(d != dist[u]) continue;

            for(auto& [v, w] : graph[u]){

                int nd = d + w;

                if(dist[v] > nd && nd < time[v]){

                    dist[v] = nd;
                    pq.push({nd, v});
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(dist[i] == INT_MAX) dist[i] = -1;
        }

        return dist;
    }
};