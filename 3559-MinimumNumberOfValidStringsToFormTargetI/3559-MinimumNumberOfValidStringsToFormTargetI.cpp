// Last updated: 6/24/2026, 3:30:28 AM
class Solution {
public:

    using ull = unsigned long long;

    const ull base = 1e6 + 3;

    int minValidStrings(vector<string>& w, string t) {

        unordered_set<ull> pref;

        for(auto &s : w){

            ull h = 0;

            for(char &c : s){

                h = h * base + c;

                pref.insert(h);
            }
        }

        int n = t.size();

        const int inf = 1e9;

        vector<int> dp(n + 1, inf);

        dp[n] = 0;

        for(int i = n - 1; i >= 0; i--){

            ull h = 0;

            for(int j = i; j < n; j++){

                h = h * base + t[j];

                if(!pref.count(h)) break;

                dp[i] = min(dp[i], 1 + dp[j + 1]);
            }
        }

        return dp[0] == inf ? -1 : dp[0];
    }
};