// Last updated: 11/6/2026, 4:56:22 AM
class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int right = accumulate(nums.begin(), nums.end(), 0);
        int left = 0;
        for(int i = 0; i < nums.size(); i++){
            right -= nums[i];
            if(left == right) return i;

            left += nums[i];
        }
        return -1;
    }
};