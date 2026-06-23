// Last updated: 6/24/2026, 3:28:23 AM
class Solution {
public:
    int minimumK(vector<int>& nums, int k = 1) {
        long long count = 0;
        for(int &i : nums){
            count += 1LL * i / k;
            if(i % k) count++;
            if(count > k * k) return minimumK(nums, k + 1);
        }
        return k;
    }
};