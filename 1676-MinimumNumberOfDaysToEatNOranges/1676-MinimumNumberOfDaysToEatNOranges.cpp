// Last updated: 6/25/2026, 11:15:42 PM
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