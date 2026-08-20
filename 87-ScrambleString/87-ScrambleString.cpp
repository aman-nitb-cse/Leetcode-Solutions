// Last updated: 8/20/2026, 9:16:07 PM
class Solution {
public:
    vector<vector<vector<vector<int>>>> dp;
    bool solve(string &s, string &t, int i, int j, int x, int y){
        auto &d = dp[i][j][x][y];
        if(d != -1) return d;
        if(i == j) return d = s[i] == t[x];
        for(int k = i; k < j; k++){
            // keep order
            if(solve(s, t, i, k, x, x + (k - i)) && solve(s, t, k + 1, j, y - (j - k - 1), y)) return d = true;
            // swap
            if(solve(s, t, i, k, y - (k - i), y) && solve(s, t, k + 1, j, x, x + (j - k - 1))) return d = true;
        }
        return d = false;
    }
    bool isScramble(string s, string t) {
        int n = s.size();
        dp.assign(n, vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n,-1))));
        return solve(s, t, 0, n - 1, 0, n - 1);
    }
};