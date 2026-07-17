// Last updated: 7/18/2026, 12:25:05 AM
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {

        vector<vector<array<int,2>>> graph(n);

        for(auto &e : roads){
            graph[e[0] - 1].push_back({e[1] - 1, e[2]});
            graph[e[1] - 1].push_back({e[0] - 1, e[2]});   // Remove for directed graph
        }

        vector<bool> vis(n);
        queue<int> q; // node 

        q.push(0);
        vis[0] = true;

        int ans = INT_MAX;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(auto& [v, w] : graph[u]){

                ans = min(ans, w);
                if(!vis[v]){
                    vis[v] = true;
                    q.push(v);
                }
            }
        }

        return ans;
    }
};