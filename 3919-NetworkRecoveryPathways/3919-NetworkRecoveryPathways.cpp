// Last updated: 7/18/2026, 12:22:14 AM
class Solution {
public:
    vector<vector<array<int,2>>> graph;
    int n;
    using ll = long long;
    bool check(int mid, ll k){

        // Dijastra Algorihtm
        vector<ll> dist(n, LLONG_MAX);

        priority_queue<array<ll,2>, vector<array<ll,2>>, greater<array<ll,2>>> pq;
        // {distance, node}

        dist[0] = 0;
        pq.push({0, 0});

        while(!pq.empty()){

            auto [d, u] = pq.top();
            pq.pop();

            if(u == n - 1) return true;

            if(d != dist[u]) continue;

            for(auto& [v, w] : graph[u]){
                ll nd = d + w;

                // total cost cant exceed k
                // we only take weigth >= mid
                if(w < mid || nd > k) continue;

                if(dist[v] > nd){

                    dist[v] = nd;
                    pq.push({nd, v});
                }
            }
        }

        return false;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& on, ll k) {
        n = on.size();
        graph.resize(n);

        int s = INT_MAX, e = INT_MIN;

        for(auto &edg : edges){
            if(on[edg[0]] && on[edg[1]]) {
                graph[edg[0]].push_back({edg[1], edg[2]});
                s = min(s, edg[2]);
                e = max(e, edg[2]);
            }
        }

        // binary search
        while(s < e){
            int mid = (s + e + 1) >> 1; // right side minimum

            if(check(mid, k)) s = mid;
            else e = mid - 1;
        }

        return check(s, k) ? s : -1;
    }
};

// maximise the minimum cost edge along valid path