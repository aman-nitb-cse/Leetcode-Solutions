// Last updated: 8/20/2026, 9:13:53 PM
class Solution {
public:
    bool dp[16][16] = {false};
    vector<vector<string>> ans;

    void solve(string& s, vector<string>& v, int i = 0) {
        if (i == s.size())
            ans.push_back(v);
        for (int j = i; j < s.size(); j++) {
            if (dp[i][j]) {
                v.push_back(s.substr(i, j - i + 1));
                solve(s, v, j + 1);
                v.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        for (int i = 0; i < 16; i++)
            dp[i][i] = true;
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i + 1; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    if (j - i == 1) dp[i][j] = true; // length 2
                    else dp[i][j] = dp[i + 1][j - 1];
                }
            }
        }

        vector<string> v;
        solve(s, v);
        return ans;
    }
};