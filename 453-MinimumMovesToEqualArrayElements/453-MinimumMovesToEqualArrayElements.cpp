// Last updated: 8/20/2026, 9:05:25 PM
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini = *ranges::min_element(nums);
        int n = nums.size();

        return accumulate(nums.begin(), nums.end(), 0) - n * mini;
    }
};