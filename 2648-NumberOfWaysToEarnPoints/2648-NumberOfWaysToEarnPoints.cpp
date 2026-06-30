// Last updated: 6/30/2026, 2:14:20 PM
class Solution {
public:
    vector<vector<int>> dp;
    const int mod = 1e9 + 7;
    int f(int t, vector<vector<int>>& T, int i){
        if(t == 0) return 1;
        if(i == T.size()) return 0;

        auto& dp_ = dp[t][i];

        if(dp_ != -1) return dp_;

        dp_ = 0;

        int count = T[i][0], marks = T[i][1];

        for(int j = 0; j <= count && t >= 0; j++, t -= marks){
            dp_ += f(t, T, i + 1);
            dp_ %= mod;
        }
        return dp_;
    }
    int waysToReachTarget(int t, vector<vector<int>>& T) {
        dp.assign(t + 1, vector<int> (T.size(), -1));
        return f(t, T, 0);
    }
};