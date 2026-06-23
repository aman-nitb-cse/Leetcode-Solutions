// Last updated: 6/24/2026, 3:26:46 AM
class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        nums.insert(nums.end(), nums.rbegin(), nums.rend());
        return nums;
    }
};