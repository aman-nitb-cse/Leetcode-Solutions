// Last updated: 8/20/2026, 8:48:41 PM
class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& fee) {
        int n = fee.size();

        vector<vector<array<int,2>>> graph(n); // {neighbor, travelTime}

        for(auto &e : edges){
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }

        vector<vector<int>> dist(n, vector<int>(maxTime + 1, INT_MAX));

        priority_queue<
            array<int,3>,
            vector<array<int,3>>,
            greater<array<int,3>>
        > pq;
        // {cost, time, node}

        dist[0][0] = fee[0];
        pq.push({fee[0], 0, 0});

        while(!pq.empty()){

            auto [cost, time, u] = pq.top();
            pq.pop();

            if(cost != dist[u][time]) continue;
            if(u == n - 1) return cost;

            for(auto &[v, travel] : graph[u]){

                int nTime = time + travel;

                int nCost = cost + fee[v];

                if(nTime <= maxTime && dist[v][nTime] > nCost){

                    dist[v][nTime] = nCost;
                    pq.push({nCost, nTime, v});
                }
            }
        }

        return -1;
    }
};