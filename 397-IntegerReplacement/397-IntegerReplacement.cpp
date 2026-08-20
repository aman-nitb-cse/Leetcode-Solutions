// Last updated: 8/20/2026, 9:06:48 PM
class Solution {
public:
    unordered_map<long long,long long> dp = {{0, 1e9}, {1, 0}};
    int integerReplacement(long long n) {
        if(dp.count(n)) return dp[n];

        if(n & 1) dp[n] = 1 + min(integerReplacement(n - 1),  integerReplacement(n + 1));
        else dp[n] = 1 + integerReplacement(n >> 1);

        return dp[n];
    }
};