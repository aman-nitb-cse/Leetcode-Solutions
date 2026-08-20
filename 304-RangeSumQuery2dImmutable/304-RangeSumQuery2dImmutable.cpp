// Last updated: 8/20/2026, 9:09:13 PM
class NumMatrix {
public:
    vector<vector<int>> v;
    int m, n;
    NumMatrix(vector<vector<int>>& matrix) : v(matrix) {
        m = v.size();
        n = v[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i) v[i][j] += v[i - 1][j];
                if(j) v[i][j] += v[i][j - 1];
                if(i && j) v[i][j] -= v[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        int ans =  v[r2][c2];

        // remove (r1, c2)
        if(r1) ans -= v[r1 - 1][c2];
        // remove (r2, c1)
        if(c1) ans -= v[r2][c1 - 1];
        // add (r1, c1)
        if(r1 && c1) ans += v[r1 - 1][c1 - 1];

        return ans;
    }
};