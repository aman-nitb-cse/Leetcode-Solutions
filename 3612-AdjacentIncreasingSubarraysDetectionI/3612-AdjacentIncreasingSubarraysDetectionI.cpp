// Last updated: 6/24/2026, 3:30:17 AM
class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        for(int i = 0; i < nums.size() - 2 * k + 1; i++){
            bool flag = true;
            for(int j = i + 1; j < i + k; j++){
                if(nums[j] < nums[j - 1] + 1) flag = false;
            }

            for(int j = i + k + 1; j < i + 2 * k; j++){
                if(nums[j] < nums[j - 1] + 1) flag = false;
            }

            if(flag) return true;
        }
        return false;
    }
};