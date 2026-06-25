// Last updated: 6/25/2026, 11:16:03 PM
class Solution {
public:

    vector<bool> vis;

    int count = 0;

    void dfs(int s, vector<vector<pair<int,int>>>& g){

        vis[s] = true;

        for(auto &[v, rev] : g[s]){

            if(vis[v]) continue;

            count += rev;

            dfs(v, g);
        }
    }

    int minReorder(int n, vector<vector<int>>& e) {

        vector<vector<pair<int,int>>> g(n);

        for(auto &i : e){

            int u = i[0];
            int v = i[1];

            // original direction
            g[u].push_back({v, 1});

            // reverse direction
            g[v].push_back({u, 0});
        }

        vis.resize(n);

        dfs(0, g);

        return count;
    }
};