// Last updated: 8/20/2026, 9:17:48 PM
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, n = nums.size(), prev = 0;

        for(int i = 0; i < n; i++){
            int curr = nums[i];

            if(prev > 0) curr += prev;

            ans = max(ans, curr);
            prev = curr;
        }
        return ans;
    }
};