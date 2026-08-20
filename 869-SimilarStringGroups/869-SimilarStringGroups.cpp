// Last updated: 8/20/2026, 8:58:40 PM
class Solution {
public:
    void dfs(int node, vector<vector<int>>& similar, vector<bool>& vis) {
        vis[node] = true;
        for (int& v : similar[node]) {
            if (!vis[v])
                dfs(v, similar, vis);
        }
    }

    int numSimilarGroups(vector<string>& w) {
        int m = w[0].size();
        int n = w.size();
        vector<bool> vis(n);
        vector<vector<int>> similar(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int diff = 0;
                for (int k = 0; k < m; k++) {
                    if (w[i][k] != w[j][k])
                        diff++;
                }
                if (diff == 2 || diff == 0) {
                    similar[i].push_back(j);
                    similar[j].push_back(i);
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i])
                continue;
            ans++;
            dfs(i, similar, vis);
        }
        return ans;
    }
};