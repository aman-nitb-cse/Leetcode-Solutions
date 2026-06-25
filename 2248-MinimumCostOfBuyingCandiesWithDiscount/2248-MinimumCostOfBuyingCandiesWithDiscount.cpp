// Last updated: 6/25/2026, 11:12:53 PM
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        ranges::sort(cost, greater<int>());
        int ans = 0, n = cost.size();
        for(int i = 0; i < n; i++){
            if(i % 3 != 2) ans += cost[i];
        }
        return ans;
    }
};