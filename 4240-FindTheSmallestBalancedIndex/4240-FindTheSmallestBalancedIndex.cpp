// Last updated: 6/24/2026, 3:27:46 AM
class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        vector<long long> sum(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++){
            sum[i] += sum[i - 1];
        }

        long long product = 1;
        int ans = 1e9;
        for(int i = nums.size() - 1; i >= 0; i--){
            long long s = i ? sum[i - 1] : 0;

            if(s == product) ans = min(ans, i);

            if(product > 1e15 / nums[i]) return ans < 1e9 ? ans : -1;
            product *= nums[i];
            
        }
        return ans < 1e9 ? ans : -1;
    }
};