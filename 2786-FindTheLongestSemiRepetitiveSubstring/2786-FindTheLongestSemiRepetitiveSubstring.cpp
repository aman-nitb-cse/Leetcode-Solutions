// Last updated: 6/24/2026, 3:32:26 AM
class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int n = s.size(), ans = 1, prev = 0;
        unordered_map<int,int> dp; // count -> index
        dp[0] = 0;
        for(int i = 1; i < n; i++){

            prev += (s[i] == s[i - 1]);
            
            if(!dp.count(prev)) dp[prev] = i;
            else ans = max(ans, i - dp[prev] + 1);

            if(dp.count(prev - 1)) ans = max(ans, i - dp[prev - 1] + 1);
        }

        // for(int &i : dp) cout << i << ' ';

        return ans;
    }
};