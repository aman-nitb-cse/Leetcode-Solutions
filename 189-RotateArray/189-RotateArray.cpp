// Last updated: 8/20/2026, 9:12:16 PM
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size(); k %= n;
        reverse(nums.begin(), nums.end() - k);
        reverse(nums.end() - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};