// Last updated: 8/20/2026, 8:54:19 PM
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& prob, int sn, int en) {
        vector<vector<pair<int,double>>> g(n);

        for(auto&& [e, p] : views::zip(edges, prob)){
            g[e[0]].push_back({e[1], p});
            g[e[1]].push_back({e[0], p});
        }

        vector<double> dist(n, 0);

        priority_queue<pair<double, int>> pq;
        // {distance, node}

        dist[sn] = 1;
        pq.push({1, sn});

        while(!pq.empty()){

            auto [d, u] = pq.top();
            pq.pop();

            if(d != dist[u]) continue;

            for(auto& [v, w] : g[u]){

                double nd = d * w;

                if(dist[v] < nd){

                    dist[v] = nd;
                    pq.push({nd, v});
                }
            }
        }

        return dist[en];
    }
};