// Last updated: 6/24/2026, 3:27:04 AM
class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> ans(n, vector<int> (m));
        vector<vector<int>> time(n, vector<int> (m, INT_MAX));

        int done = 0;
        queue<array<int, 3>> q; // r, c, colour
        for(auto &s : sources){
            int i = s[0], j = s[1], c = s[2];
            if(time[i][j] == 0) ans[i][j] = max(ans[i][j], c);
            else {
                time[i][j] = 0; 
                ans[i][j] = c;
            }
        }

        for(auto &s : sources) q.push({s[0], s[1], ans[s[0]][s[1]]});

        while(!q.empty()){
            auto [i, j, c] = q.front(); q.pop();
            if(c != ans[i][j]) continue;
            int d[5] = {1, 0, -1, 0, 1};

            for(int k = 0; k < 4; k++){
                int _i = i + d[k];
                int _j = j + d[k+1];
            
                if(_i < 0 || _j < 0 || _i >= n || _j >= m || time[i][j] + 1 > time[_i][_j]) continue;
            
                if(time[i][j] + 1 < time[_i][_j]){
                    time[_i][_j] = time[i][j] + 1;
                    ans[_i][_j] = c;
                    q.push({_i, _j, c});
                }
                else if(c > ans[_i][_j]){
                    ans[_i][_j] = c;
                    q.push({_i, _j, c});
                }
            }
        }
        return ans;
    }
};