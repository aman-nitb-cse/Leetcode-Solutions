// Last updated: 8/20/2026, 9:08:32 PM
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int count = 0, i = 0;
        for (long long k = 1; k <= n; count++)
            k += (i < nums.size() && nums[i] <= k) ? nums[i++] : k;
        return count - i;
    }
};