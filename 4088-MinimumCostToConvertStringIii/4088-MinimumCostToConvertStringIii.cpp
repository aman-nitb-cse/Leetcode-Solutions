// Last updated: 8/20/2026, 8:34:55 PM
class Solution {
public:
    using ll = long long;
    ll dp[5000];
    int f(string &s, int idx, string &t, vector<vector<string>>& v, vector<int> & cost){
        if(idx == s.size()) return 0;

        if(dp[idx] != -1) return dp[idx];

        ll skip = INT_MAX;

        if(s[idx] == t[idx]){
            skip = f(s, idx + 1, t, v, cost);
        }
        
        ll take = INT_MAX;

        for(int i = 0; i < v.size(); i++){
            bool valid = true;

            ll cnt = 0;
            int n = v[i][0].size();

            for(int j = 0; j < n && idx + j < s.size(); j++){
                if((s[idx + j] != v[i][0][j] && v[i][0][j] != '*')){
                    valid = false;
                    break;
                }

                if((t[idx + j] != v[i][1][j])){
                    valid = false;
                    break;
                }

                if(v[i][0][j] == '*') cnt++;
            }

            if(valid && idx + n <= s.size()){
                take = min(take, 0LL + cost[i] + cnt + f(s, idx + n, t, v, cost));
            }
        }

        return dp[idx] = min(take, skip);
    }
    int minCost(string s, string t, vector<vector<string>>& rules, vector<int>& costs) {
        memset(dp, -1, sizeof(dp));
        ll ans = f(s, 0, t, rules, costs);

        if(ans >= 1e9) return -1;
        return ans;
    }
};