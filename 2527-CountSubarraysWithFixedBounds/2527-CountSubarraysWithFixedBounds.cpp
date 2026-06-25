// Last updated: 6/25/2026, 11:11:32 PM
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long cnt = 0;

        int invalid = -1, mn = -1, mx = -1;

        for(int i = 0; i < nums.size(); i++){

            if(nums[i] < minK || nums[i] > maxK) invalid = i;

            if(nums[i] == minK) mn = i;

            if(nums[i] == maxK) mx = i;

            cnt += max(0, min(mn, mx) - invalid);
        }

        return cnt;
    }
};