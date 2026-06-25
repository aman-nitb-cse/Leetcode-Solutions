// Last updated: 6/25/2026, 11:11:20 PM
#define ll long long
class Solution {
public:
    vector<vector<ll>> dp;

    ll solve(int i, int j, vector<int>& robot, vector<vector<int>>& factory){
        if(i == robot.size()) return 0;
        if(j == factory.size()) return 1e18;

        auto& ans = dp[i][j];
        if(ans != -1) return ans;

        ans = solve(i, j+1, robot, factory); // skip factory

        ll dist = 0;
        int pos = factory[j][0], limit = factory[j][1];

        for(int k = 0; k < limit && i + k < robot.size(); k++){
            dist += abs(robot[i+k] - pos);
            ans = min(ans, dist + solve(i+k+1, j+1, robot, factory));
        }
        return ans;
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        ranges::sort(robot);
        ranges::sort(factory);

        dp.assign(robot.size(), vector<ll>(factory.size(), -1));
        return solve(0, 0, robot, factory);
    }
};