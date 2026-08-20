// Last updated: 8/20/2026, 8:47:28 PM
class Solution {
public:
    vector<vector<array<int,2>>> graph;
    vector<bool> vis;
    int ans = 0;
    void dfs(int node, vector<int>& values, int maxTime, int sum){
        if(maxTime < 0) return;
        if(node == 0) ans = max(ans, sum);

        for(auto& [nbr, t] : graph[node]){
            bool ov = vis[nbr];
            int nSum = values[nbr] * !ov + sum;
            vis[nbr] = true;
            dfs(nbr, values, maxTime - t, nSum);
            vis[nbr] = ov;
        }
    }
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
        graph.resize(n);
        vis.resize(n);

        for(auto &e : edges){
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }
        vis[0] = true;
        dfs(0, values, maxTime, values[0]);
        return ans;
    }
};

// max(sum(value of unique nodes in path)) 0 -> 0