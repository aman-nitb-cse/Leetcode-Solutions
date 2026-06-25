// Last updated: 6/25/2026, 11:13:48 PM
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