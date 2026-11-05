// Last updated: 11/6/2026, 5:10:09 AM
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int &i : nums) i *= i;
        sort(nums.begin(), nums.end());
        return nums;
    }
};