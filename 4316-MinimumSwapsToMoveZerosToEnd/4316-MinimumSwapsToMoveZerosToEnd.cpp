// Last updated: 6/24/2026, 3:26:33 AM
class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();
        int z = ranges::count(nums, 0);
        return count(nums.begin(), nums.end() - z, 0);
    }
};