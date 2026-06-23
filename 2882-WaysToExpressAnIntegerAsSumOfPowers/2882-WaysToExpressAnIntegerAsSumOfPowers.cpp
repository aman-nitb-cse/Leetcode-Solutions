// Last updated: 6/24/2026, 3:32:12 AM
class Solution {
public:
    vector<vector<long long>> dp;
    int solve(int target, int power, int num){
        if(target == 0) return 1;
        if(target < 0 || num == 0) return 0; 
        if(dp[num][target] == -1) dp[num][target] = 1LL * solve(target, power, num - 1) + solve(target - pow(num, power), power, num - 1);
        dp[num][target] %= 1000000007;
        return dp[num][target];
    }
    int numberOfWays(int n, int x) {
        if(n == 1) return 1;
        int max_num = 1;
        while(pow(max_num, x) <= n) max_num++;
        max_num--;
        dp.assign(max_num + 1, vector<long long>(n + 1, -1));
        return solve(n, x, max_num) % (1000000007);
    }
};