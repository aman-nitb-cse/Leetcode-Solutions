// Last updated: 6/24/2026, 3:28:15 AM
class Solution {
public:
    
    vector<int> dp;
    int e, f;

    long long solve(string &s, int start, int end){
        int start_x = start ? dp[start - 1] : 0;
        int end_x = dp[end];
        int x = end_x - start_x;
        int n = end - start + 1;
        long long cost = x ? 1LL * x * n * e : f;

        if(n & 1) return cost;
        int mid = start + (end - start) / 2;
        return min(cost, solve(s, start, mid) + solve(s, mid + 1, end));
    }
    
    long long minCost(string s, int encCost, int flatCost, int start = 0, int end = -1) {
        int n = s.size();
        e = encCost;
        f = flatCost;
        dp.resize(n);
        for(int i = 0; i < n; i++){
            dp[i] = (s[i] == '1');

            if(i) dp[i] += dp[i - 1];
        }

        return solve(s, 0, n - 1);
    }
};