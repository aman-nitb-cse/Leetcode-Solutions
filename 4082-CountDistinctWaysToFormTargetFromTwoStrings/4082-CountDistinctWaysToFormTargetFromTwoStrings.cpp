// Last updated: 7/18/2026, 12:21:51 AM
#define ll long long

class Solution {
public:
    static constexpr ll MOD = 1e9 + 7;

    int lenT, lenA, lenB;
    vector<vector<vector<ll>>> dp;

    int interleaveCharacters(string word1, string word2, string target) {
        lenT = target.size();
        lenA = word1.size();
        lenB = word2.size();

        dp.assign(lenT, vector<vector<ll>>(lenA + 1, vector<ll>(lenB + 1, -1)));

        return solve(word1, word2, target, 0, -1, -1);
    }

    ll solve(string &word1, string &word2, string &target, int idx, int last1, int last2) {

        if (idx == lenT) return (last1 != -1 && last2 != -1);

        ll &ans = dp[idx][last1 + 1][last2 + 1];
        if (ans != -1) return ans;

        ans = 0;

        for (int i = last1 + 1; i < lenA; i++) {
            if (word1[i] == target[idx]) {
                ans += solve(word1, word2, target, idx + 1, i, last2);
                ans %= MOD;
            }
        }

        for (int i = last2 + 1; i < lenB; i++) {
            if (word2[i] == target[idx]) {
                ans += solve(word1, word2, target, idx + 1, last1, i);
                ans %= MOD;
            }
        }

        return ans;
    }
};