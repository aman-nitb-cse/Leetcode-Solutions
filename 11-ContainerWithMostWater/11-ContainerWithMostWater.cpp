// Last updated: 8/20/2026, 9:20:01 PM
class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for(int s = 0, e = n - 1; e >= 0 && s < n;){
            ans = max(ans, 1LL * (e - s) * min(nums[s], nums[e]));

            if(nums[s] > nums[e]) e--;
            else s++;
        }
        return ans;
    }
};