// Last updated: 11/6/2026, 4:39:21 AM
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        ranges::sort(nums, [&](int a, int b){
            return abs(a) < abs(b);
        });

        long long ans = 0;

        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(i < n / 2) ans -= 1LL * nums[i] * nums[i];
            else ans += 1LL * nums[i] * nums[i];
        }

        return ans;
    }
};