// Last updated: 8/20/2026, 9:08:00 PM
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& env) {
        ranges::sort(env, 
            [](auto &a, auto &b){
                if(a[0] == b[0]) return a[1] > b[1];
                return a[0] < b[0];
            }
        );

        map<int, int> dp;
        dp[INT_MIN] = 0;
        int ans = 0;
        for(auto &v : env){
            int x = v[1];
            dp[x] = 1 +  prev(dp.lower_bound(x))->second;

            auto it = dp.upper_bound(x);
            while(it != dp.end() && it->second <= dp[x]){
                it = dp.erase(it);
            }
        }
        return dp.rbegin()->second;
    }
};