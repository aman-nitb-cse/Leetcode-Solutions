// Last updated: 11/6/2026, 4:33:19 AM
class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        nums.insert(nums.end(), nums.rbegin(), nums.rend());
        return nums;
    }
};