// Last updated: 6/25/2026, 11:16:01 PM
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int s = 0, e = 0, n = nums.size(), ans = 0;
        int zeros = 1 - nums[0];
        while(e < n){
            if(zeros <= 1){
                ans = max(
                    ans, 
                    min(n - 1, e - s + 1 - zeros)
                );
                e++;
                if(e < n) zeros += 1 - nums[e];
            }
            else zeros -= 1 - nums[s++];
        }
        return ans;
    }
};