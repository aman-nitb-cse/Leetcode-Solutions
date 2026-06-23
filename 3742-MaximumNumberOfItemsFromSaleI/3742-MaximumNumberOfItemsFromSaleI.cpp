// Last updated: 6/24/2026, 3:30:04 AM
class Solution {
public:
    vector<int> free;

    int dp[1000][1501][2];

    int solve(int idx, vector<vector<int>>& items, bool taken, int budget){

        if(idx == items.size() || budget == 0) return 0;

        auto &_dp = dp[idx][budget][taken];
        if(_dp != -1) return _dp;

        // take
        if(budget >= items[idx][1]){
            _dp = max(_dp, 1 + free[idx] * !taken + solve(idx, items, true, budget - items[idx][1]));
        }

        // skip
        _dp = max(_dp, solve(idx + 1, items, false, budget));

        return _dp;
    }

    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        int n = items.size();

        free.assign(n, 0);

        for(int i = 0; i < n; i++){

            for(int j = 0; j < n; j++){

                if(i ^ j && items[j][0] % items[i][0] == 0) free[i]++;
            }
        }

        memset(dp, -1, sizeof(dp));

        return solve(0, items, false, budget);
    }
};