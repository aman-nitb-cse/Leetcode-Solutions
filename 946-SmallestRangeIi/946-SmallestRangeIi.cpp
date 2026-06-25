// Last updated: 6/25/2026, 11:19:54 PM
class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {

        k <<= 1;

        ranges::sort(nums);

        int n = nums.size(), maxi = nums.back();

        int ans = maxi - nums.front();

        int prev_min = INT_MAX, prev_max = INT_MIN;

        for(int i = 0; i < n - 1; i++){

            nums[i] += k;

            prev_min = min(prev_min, nums[i]);
            prev_max = max(prev_max, nums[i]);


            int mini = min(nums[i + 1], prev_min);
            int maxi = max(nums.back(), prev_max);


            ans = min(ans, maxi - mini);
        }

        return ans;
    }
};