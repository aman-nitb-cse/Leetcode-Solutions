// Last updated: 6/24/2026, 3:31:31 AM
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {

        long long ans = -1, pref = 0;

        ranges::sort(nums);

        for(int i = 0; i < nums.size(); i++){
            if(i >= 2 && pref > nums[i]) ans = max(ans, pref + nums[i]);

            pref += nums[i];
        }

        return ans;
    }
};