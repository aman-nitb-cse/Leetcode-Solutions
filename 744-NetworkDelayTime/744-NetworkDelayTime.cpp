// Last updated: 8/20/2026, 9:00:14 PM
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& edges, int n, int k) {
        vector<vector<array<int,2>>> graph(n); // {neighbor, weight}

        for(auto &e : edges){
            graph[e[0] - 1].push_back({e[1] - 1, e[2]});
        }

        vector<int> dist(n, INT_MAX);

        priority_queue<array<int,2>, vector<array<int,2>>, greater<array<int,2>>> pq; // {distance, node}

        dist[k - 1] = 0;
        pq.push({0, k - 1});

        while(!pq.empty()){
            auto [d, u] = pq.top();
            pq.pop();

            if(d != dist[u]) continue;

            for(auto [v, w] : graph[u]){
                int nd = d + w;

                if(dist[v] > nd){
                    dist[v] = nd;
                    pq.push({nd, v});
                }
            }
        }

        int mx = ranges::max(dist);

        return (mx == INT_MAX) ? -1 : mx;
    }
};