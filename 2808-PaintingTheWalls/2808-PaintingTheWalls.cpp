// Last updated: 8/20/2026, 8:42:41 PM
class Solution {
public:
    int dp[500][1005];
    int f(vector<int>& cost, vector<int>& time, int i, int t){
        if(i == cost.size()) {
            if(t >= 0) return 0;
            return 1e9;
        }

        int &ans = dp[i][t + 500];

        if(ans != -1) return ans;

        // by paid painter
        int paid = cost[i] + f(cost, time, i + 1, min(500, t + time[i]));

        // by free painter
        int free = f(cost, time, i + 1, t - 1);

        return ans = min(paid, free);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        memset(dp, -1, sizeof(dp));
        return f(cost, time, 0, 0);
    }
};

// t <= 250000
// tf <= 500