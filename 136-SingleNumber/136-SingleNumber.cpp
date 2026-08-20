// Last updated: 8/20/2026, 9:13:39 PM
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) ans ^= nums[i];
        return ans;
    }
};