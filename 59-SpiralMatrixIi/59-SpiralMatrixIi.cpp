// Last updated: 8/20/2026, 9:17:29 PM
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n, vector<int>(n, 0));
        int t = 1, loop = 0;
        while(t <= n * n){
            for(int i = loop; i < n - loop; i++) v[loop][i] = t++;
            for(int i = loop + 1; i < n - loop; i++) v[i][n - loop - 1] = t++;
            for(int i = n - loop - 2; i >= loop; i--) v[n - loop - 1][i] = t++;
            for(int i = n - loop - 2; i > loop; i--) v[i][loop] = t++;
            loop++;
        }
        return v;
    }
};