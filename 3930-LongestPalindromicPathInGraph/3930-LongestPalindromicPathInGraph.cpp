// Last updated: 8/20/2026, 8:36:28 PM
class Solution {
    vector<vector<int>> graph;
    
    int dp[14][14][16384];

    int dfs(int node1, int node2, int mask, const string& ch) {
        if (node1 > node2) swap(node1, node2);
        
        int& ans = dp[node1][node2][mask];

        if (ans != -1) return ans;

        ans = 0;

        for (int& u : graph[node1]) {
            if ((mask >> u) & 1) continue; 

            for (int& v : graph[node2]) {

                if (u == v || ch[u] != ch[v] || (mask >> v) & 1) continue;         
                
                ans = max(ans, 2 + dfs(u, v, mask | (1 << u) | (1 << v), ch));
            }
        }

        return ans;
    }

public:
    int maxLen(int n, vector<vector<int>>& edges, string label) {
        graph.assign(n, vector<int>());

        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        memset(dp, -1, sizeof(dp));
        
        int ans = 1;


        for (int i = 0; i < n; i++) {

            ans = max(ans, 1 + dfs(i, i, 1 << i, label));

        }

        for (auto &e : edges) {

            int u = e[0], v = e[1];

            if (label[u] == label[v]) {

                ans = max(ans, 2 + dfs(u, v, (1 << u) | (1 << v), label));

            }
        }

        return ans;
    }
};