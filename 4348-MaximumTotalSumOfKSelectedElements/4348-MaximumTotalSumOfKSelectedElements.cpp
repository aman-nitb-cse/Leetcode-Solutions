// Last updated: 6/30/2026, 1:26:26 PM
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