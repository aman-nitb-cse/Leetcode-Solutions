// Last updated: 6/25/2026, 11:11:50 PM
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int s = 0, e = 0, n = nums.size();
        int mask = 0;
        int ans = 1;
        while(s <= e && e < n){

            // invalid : shrink till valid condition
            while(mask & nums[e]) mask ^= nums[s++];

            // expend always
            ans = max(ans, e - s + 1);
            mask |= nums[e++];
        }
        return ans;
    }
};