// Last updated: 6/24/2026, 3:30:42 AM
class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        double mini = INT_MAX;
        int n = nums.size();
        for(int i = 0; i <= n / 2; i++){
            mini = min(mini, (nums[i] + nums[n - i - 1]) / 2.0);
        }
        return mini;
    }
};