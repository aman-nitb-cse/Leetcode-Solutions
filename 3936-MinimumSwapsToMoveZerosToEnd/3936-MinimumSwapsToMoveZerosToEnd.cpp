// Last updated: 11/6/2026, 4:32:45 AM
class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();
        int z = ranges::count(nums, 0);
        return count(nums.begin(), nums.end() - z, 0);
    }
};