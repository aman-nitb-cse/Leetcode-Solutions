// Last updated: 11/6/2026, 5:10:45 AM
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int e = 0; // even index
        int o = 1; // odd index
        int n = nums.size();

        while (e < n && o < n) {
            if (!(nums[e] & 1)) {
                e += 2; // correct even
            }
            else if (nums[o] & 1) {
                o += 2; // correct odd
            }
            else {
                swap(nums[e], nums[o]); // fix both
            }
        }
        return nums;
    }
};