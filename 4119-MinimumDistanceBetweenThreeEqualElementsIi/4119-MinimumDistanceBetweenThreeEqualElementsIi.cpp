// Last updated: 6/24/2026, 3:28:45 AM
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> last(n, {-1, -1});
        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            auto &[x, y] = last[nums[i] - 1];
            if(x != -1) ans = min(ans, 2 * (i - x));

            x = y;
            y = i;
        }
        return ans < INT_MAX ? ans : -1;
    }
};