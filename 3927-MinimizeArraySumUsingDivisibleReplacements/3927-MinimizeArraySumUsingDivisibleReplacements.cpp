// Last updated: 11/6/2026, 4:33:11 AM
class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        ranges::sort(nums);

        if(ranges::binary_search(nums, 1)) return nums.size();

        long long sum = 0;

        for(int n : nums){
            int best = n;
            for(int i = 2; i * i <= n; i++){
                if(n % i) continue;
                if(ranges::binary_search(nums, i)) best = min(best, i);
                if(ranges::binary_search(nums, n / i)) best = min(best, n / i);
            }

            sum += best;
        }

        return sum;
    }
};