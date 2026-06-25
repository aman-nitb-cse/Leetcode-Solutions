// Last updated: 6/25/2026, 11:18:31 PM
class Solution {
public:
    bool check(string &s, string &t, int i = 0, int j = 0, bool flag = true){
        if(i == s.size() && j == t.size()) return true;
        if(i == s.size()) return false;
        if(j == t.size()) return flag;
        if(s[i] == t[j]) return check(s, t, i + 1, j + 1, flag);
        return flag && check(s, t, i + 1, j, false);
    }
    int longestStrChain(vector<string>& w) {
        ranges::sort(w, [](auto &a, auto &b){
            return a.size() < b.size();
        });
        int n = w.size();
        vector<int> dp(n);
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i - 1; j >= 0; j--){
                if(w[i].size() == w[j].size()) continue;
                if(w[i].size() != w[j].size() + 1) break;

                // check can we take w[j]
                if(check(w[i], w[j])) dp[i] = max(dp[i], dp[j]);
            }
            dp[i]++;

            ans = max(ans, dp[i]);
        }
        return ans;
    }
};