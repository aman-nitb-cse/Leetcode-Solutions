// Last updated: 6/24/2026, 3:30:35 AM
class NeighborSum {
public:
    vector<vector<int>>& v;
    int m, n;
    NeighborSum(vector<vector<int>>& grid) : v(grid) {
        m = v.size();
        n = v[0].size();
    }

    int adjacentSum(int value) {
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(v[i][j] == value){
                    int ans = 0;
                    if(j + 1 < n) ans += v[i][j + 1]; 
                    if(j - 1 >= 0) ans += v[i][j - 1];
                    if(i - 1 >= 0) ans += v[i - 1][j];
                    if(i + 1 < m) ans += v[i + 1][j];
                    return ans;
                }
            }
        }
        return 0;
    }

    int diagonalSum(int value) {
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(v[i][j] == value){
                    int ans = 0;
                    if(j + 1 < n && i + 1 < m) ans += v[i + 1][j + 1]; 
                    if(j - 1 >= 0 && i - 1 >= 0) ans += v[i - 1][j - 1];
                    if(i - 1 >= 0 && j + 1 < n) ans += v[i - 1][j + 1];
                    if(i + 1 < m && j - 1 >= 0) ans += v[i + 1][j - 1];
                    return ans;
                }
            }
        }
        return 0;
    }
};