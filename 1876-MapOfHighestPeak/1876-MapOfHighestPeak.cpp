// Last updated: 8/20/2026, 8:49:59 PM
class Solution {
public:
    static constexpr int dir[] = {1, 0, -1, 0, 1};
    vector<vector<int>> highestPeak(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        queue<array<int,2>> q; // {i, j}

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j]){
                    mat[i][j] = 0;
                    q.push({i, j});
                }
                else{
                    mat[i][j] = -1;
                }
            }
        }

        

        while(!q.empty()){
            auto [i, j] = q.front(); q.pop();

            for(int d = 0; d < 4; d++){
                int ni = i + dir[d];
                int nj = j + dir[d + 1];

                if(ni >= 0 && nj >= 0 && ni < m && nj < n && mat[ni][nj] == -1){
                    mat[ni][nj] = mat[i][j] + 1;
                    q.push({ni, nj});
                }
            }
        }

        return mat;
    }
};