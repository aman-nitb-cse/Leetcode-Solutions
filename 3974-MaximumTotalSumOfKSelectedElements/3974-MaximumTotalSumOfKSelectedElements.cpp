// Last updated: 11/6/2026, 4:31:57 AM
class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        ranges::sort(nums);

        long long sum = 0;

        while(k--){
            long long x = nums.back(); nums.pop_back();
            sum += x * mul;
            if(mul > 1) mul--;
        }

        return sum;
    }
};