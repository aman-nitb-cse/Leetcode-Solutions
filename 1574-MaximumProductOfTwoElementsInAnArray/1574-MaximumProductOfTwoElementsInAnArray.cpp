// Last updated: 8/20/2026, 8:51:54 PM
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                ans = max(ans, (nums[i] - 1) * (nums[j] - 1));
            }
        }
        
        return ans;
    }
};