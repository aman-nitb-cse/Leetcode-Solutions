// Last updated: 11/6/2026, 4:38:31 AM
class Solution {
public:
    int finalElement(vector<int>& nums) {
        return max(nums.front(), nums.back());
    }
};