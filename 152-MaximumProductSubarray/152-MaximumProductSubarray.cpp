// Last updated: 8/20/2026, 9:12:58 PM
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int p = 0, n = 0;
        if(nums[0] > 0) p = nums[0];
        else n = nums[0];
        int ans = nums[0];
        for(int i = 1; i < nums.size(); i++){
            int _p = max({0, nums[i], nums[i] * p, nums[i] * n});
            int _n = min({0, nums[i], nums[i] * p, nums[i] * n});

            ans = max(ans, _p);

            p = _p;
            n = _n;
        }
        return ans;
    }
};