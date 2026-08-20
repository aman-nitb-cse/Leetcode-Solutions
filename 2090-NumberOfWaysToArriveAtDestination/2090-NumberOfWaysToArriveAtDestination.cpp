// Last updated: 8/20/2026, 8:48:20 PM
class Solution {
public: 
    using ll = long long;
    const int mod = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& edges) {
        vector<vector<array<int,2>>> graph(n);

        for(auto &e : edges){
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }

        vector<ll> paths(n), dist(n, LLONG_MAX);

        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
        // {distance, node}

        dist[0] = 0;
        paths[0] = 1;
        pq.push({0, 0});

        while(!pq.empty()){

            auto [d, u] = pq.top();
            pq.pop();

            if(d != dist[u]) continue;

            for(auto& [v, w] : graph[u]){

                ll nd = d + w;

                if(dist[v] > nd){
                    dist[v] = nd;
                    paths[v] = paths[u];
                    pq.push({nd, v});
                }
                else if(dist[v] == nd){
                    paths[v] += paths[u];
                    paths[v] %= mod;
                }
            }
        }

        return paths[n - 1];
    }
};