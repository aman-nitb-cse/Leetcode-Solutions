// Last updated: 8/20/2026, 8:55:12 PM
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& r, vector<vector<int>>& b) {

        // initialization
        vector<vector<int>> R(n), B(n);

        for(auto &e : r) R[e[0]].push_back(e[1]);
        for(auto &e : b) B[e[0]].push_back(e[1]);
        

        queue<array<int,2>> q; // {node, flag}

        // 0 : red
        // 1 : blue
        // -1 : red + blue

        vector<array<int,2>> vis(n, {INT_MAX, INT_MAX});
        q.push({0, -1});

        vis[0] = {0, 0};

        while(!q.empty()){
            auto [node, flag] = q.front(); q.pop();

            for(int i = 0; i <= 1; i++){
                if(flag != i){
                    for(int &nbr : i ? B[node] : R[node]){
                        if(vis[nbr][!i] > vis[node][i] + 1){
                            vis[nbr][!i] = vis[node][i] + 1;
                            q.push({nbr, i});
                        }
                    }
                }
            }
        }
        vector<int> ans(n, -1);

        for(int i = 0; i < n; i++){
            ans[i] = min(vis[i][0], vis[i][1]);
            if(ans[i] == INT_MAX) ans[i] = -1;
        }

        return ans;
    }
};