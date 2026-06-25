// Last updated: 6/25/2026, 11:11:39 PM
class Solution {
public:

    using ull = unsigned long long;

    const ull base = 1e6 + 3;

    int deleteString(string s) {

        int n = s.size();

        vector<ull> pref(n), pw(n, 1);

        pref[0] = s[0];

        for(int i = 1; i < n; i++){

            pref[i] = pref[i - 1] * base + s[i];

            pw[i] = pw[i - 1] * base;
        }

        auto hash = [&](int i, int len){

            int r = i + len - 1;

            if(i == 0) return pref[r];

            return pref[r] - pw[len] * pref[i - 1];
        };

        vector<int> dp(n + 1, 1);

        dp[n] = 0;

        for(int i = n - 1; i >= 0; i--){

            for(int len = 1; i + 2 * len <= n; len++){

                if(hash(i, len) == hash(i + len, len)){

                    dp[i] = max(dp[i], 1 + dp[i + len]);
                }
            }
        }

        return dp[0];
    }
};