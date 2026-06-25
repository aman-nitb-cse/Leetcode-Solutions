// Last updated: 6/25/2026, 11:10:35 PM
class Solution {
public:
    int minExtraChar(string &s, vector<string>& d) {
        unordered_set<string> dict(d.begin(), d.end());
        int n = s.size();
        vector<vector<int>> v(n); // v[i] = {x : substring(i, x) ∈ dict}

        for(int i = 0; i < n; i++){
            string temp = "";
            for(int j = i; j < n; j++){
                temp += s[j];
                if(dict.count(temp)) v[j].push_back(i);
            }
        }

        vector<int> dp(n, 1e9);
        for(int i = 0; i < n; i++){
            for(int& start : v[i]){
                dp[i] = start ? min(dp[i], dp[start - 1]) : 0;
            }
            dp[i] = i ? min(dp[i], 1 + dp[i - 1]) : dp[i] = min(dp[i], 1);
        }
        return dp.back();
    }
};