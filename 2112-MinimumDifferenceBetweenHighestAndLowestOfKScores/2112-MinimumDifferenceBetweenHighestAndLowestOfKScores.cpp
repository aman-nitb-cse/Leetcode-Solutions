// Last updated: 6/25/2026, 11:13:45 PM
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0, j = k - 1;
        int mini = INT_MAX;
        while(j < nums.size()){
            mini = min(mini, nums[j++] - nums[i++]);
        }
        return mini;
    }
};