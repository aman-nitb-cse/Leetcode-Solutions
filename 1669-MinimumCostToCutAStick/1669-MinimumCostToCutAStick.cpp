// Last updated: 6/25/2026, 11:15:46 PM
class Solution {
public:
    unordered_map<long long, int> dp;

    int minCost(long long e, vector<int>& cuts, int s = 0) {
        long long key = (e << 32) | s;
        if(dp.count(key)) return dp[key];

        int cost = INT_MAX;

        for(int &i : cuts){
            if(i < e && i > s){
                cost = min(cost, minCost(i, cuts, s) + minCost(e, cuts, i));
            }
        }

        if(cost == INT_MAX) return dp[key] = 0;

        return dp[key] = cost + (e - s);
    }
};