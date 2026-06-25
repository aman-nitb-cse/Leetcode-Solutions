// Last updated: 6/25/2026, 11:13:11 PM
class Solution {
public:

    vector<vector<int>> graph;

    vector<int> vis;

    int ans = 1;

    int dfs(int i){
        vis[i] = true;
        int cnt = 0;
        for(int &nbr : graph[i]){
            if(!vis[nbr]){
                cnt += dfs(nbr);
            }
        }
        ans = max(ans, ++cnt);
        return cnt;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();

        graph.resize(n);

        for(int i = 0; i < n; i++){

            int x1 = bombs[i][0], y1 = bombs[i][1], r = bombs[i][2];

            for(int j = 0; j < n; j++){

                int x2 = bombs[j][0], y2 = bombs[j][1];

                long long dx = x1 - x2;
                long long dy = y1 - y2;

                if(dx * dx + dy * dy <= 1LL * r * r) graph[i].push_back(j);
            }
        }

        for(int i = 0; i < n; i++) {
            vis.assign(n, false);
            dfs(i);
        }

        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < graph[i].size(); j++){
        //         cout << graph[i][j] << ' ';
        //     }
        //     cout << endl;
        // }

        return ans;
    }
};