// Last updated: 11/6/2026, 5:01:21 AM
class Solution {
public:
    unordered_map<int, int> dp;
    int minDays(int n) {
        if(n <= 2) return n;
        if(!dp.count(n)) dp[n] = 1 + min(
            n % 2 + minDays(n / 2),
            n % 3 + minDays(n / 3)
        );
        return dp[n];
    }
};