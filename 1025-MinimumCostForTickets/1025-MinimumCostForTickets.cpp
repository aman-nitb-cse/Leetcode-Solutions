// Last updated: 8/20/2026, 8:56:52 PM
class Solution {
public:
    bitset<365> bit;
    int dp[365];
    int f(int d, vector<int>& cost){

        if(d >= 365) return 0;

        if(dp[d] != -1) return dp[d];

        if(!bit[d]) return dp[d] = f(d + 1, cost);

        return dp[d] = min({
            cost[0] + f(d + 1, cost),
            cost[1] + f(d + 7, cost),
            cost[2] + f(d + 30, cost)
        });

    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        for(int &i : days) bit.set(i - 1);

        memset(dp, -1, sizeof(dp));

        return f(0, costs);
    }
};