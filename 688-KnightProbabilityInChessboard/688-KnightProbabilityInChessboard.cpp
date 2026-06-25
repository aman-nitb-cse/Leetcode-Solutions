// Last updated: 6/25/2026, 11:37:13 PM
class Solution {
public:
    vector<vector<vector<double>>> dp = vector<vector<vector<double>>> (101, vector<vector<double>> (25, vector<double> (25, -1)));
    double knightProbability(int n, int k, int r, int c, double p = 1) {
        if(r < 0 || r >= n || c < 0 || c >= n) return 0;
        if(k == 0) return p;
        auto &_dp = dp[k][r][c];
        if(_dp != -1) return _dp;
        _dp = 0;
        for(int i : {1, -1}){
            for(int j : {2, -2}){
                _dp += knightProbability(n, k - 1, r + i, c + j, p / 8);
                _dp += knightProbability(n, k - 1, r + j, c + i, p / 8);
            }
        }
        return _dp;
    }
};