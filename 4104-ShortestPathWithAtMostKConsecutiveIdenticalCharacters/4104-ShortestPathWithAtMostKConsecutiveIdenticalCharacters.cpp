// Last updated: 6/24/2026, 3:28:50 AM
class Solution {
public:
    using ll = long long;

    const ll INF = 4e18;

    int shortestPath(int n, vector<vector<int>>& edges, string ch, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto &e : edges){
            adj[e[0]].push_back({e[1], e[2]});
        }

        vector<vector<ll>> dist(n, vector<ll>(k + 1, INF));

        priority_queue<array<ll,3>> pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while(!pq.empty()){

            auto [d, u, streak] = pq.top();
            pq.pop();

            d *= -1;

            if(d != dist[u][streak]) continue;

            for(auto &[v, w] : adj[u]){

                int newStreak =
                    (ch[u] == ch[v] ? streak + 1 : 1);

                if(newStreak > k) continue;

                ll nd = d + w;

                if(nd < dist[v][newStreak]){

                    dist[v][newStreak] = nd;
                    pq.push({-nd, v, newStreak});
                }
            }
        }

        ll ans = ranges::min(dist[n - 1]);

        return ans == INF ? -1 : (int)ans;
    }
};