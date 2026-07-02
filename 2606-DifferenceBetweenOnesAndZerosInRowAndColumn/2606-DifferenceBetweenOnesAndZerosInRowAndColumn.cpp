// Last updated: 7/2/2026, 11:38:20 PM
class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();

        vector<int> onesRow(m), onesCol(n);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++) {
                if(g[i][j]) {
                    onesRow[i]++;
                    onesCol[j]++;
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++) {
                g[i][j] = (onesRow[i] + onesCol[j]) * 2 - m - n;
            }
        }
        return g;
    }
};