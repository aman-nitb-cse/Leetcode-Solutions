// Last updated: 7/18/2026, 12:21:24 AM
class Solution {
public:
    using ll = long long;

    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int x, int y) {
        vector<vector<array<int,2>>> graph(n);

        for(auto &e : edges){
            graph[e[0]].push_back({e[1], e[2]});
        }

        const ll inf = 1e18;

        vector<vector<ll>> dist(n, vector<ll>(power + 1, inf));

        priority_queue<array<ll,3>, vector<array<ll,3>>, greater<array<ll,3>>> pq;
        // {time, node, remainingPower}

        dist[x][power] = 0;
        pq.push({0, x, power});

        ll bestTime = -1;
        ll bestPower = -1;

        while(!pq.empty()){

            auto [d, u, cp] = pq.top();
            pq.pop();

            if(d != dist[u][cp]) continue;

            if(bestTime != -1 && d > bestTime) break;

            if(u == y){

                if(bestTime == -1) bestTime = d;

                bestPower = max(bestPower, cp);
                continue;
            }

            if(cp < cost[u]) continue;

            ll np = cp - cost[u];

            for(auto &[v, w] : graph[u]){

                if(d + w < dist[v][np]){

                    dist[v][np] = d + w;
                    pq.push({d + w, v, np});
                }
            }
        }

        return {bestTime, bestPower};
    }
};