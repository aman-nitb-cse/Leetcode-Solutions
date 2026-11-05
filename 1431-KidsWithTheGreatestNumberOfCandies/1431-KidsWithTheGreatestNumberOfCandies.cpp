// Last updated: 11/6/2026, 5:03:02 AM
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& nums, int k) {
        int maxi = ranges::max(nums);
        
        for(int &i : nums){
            i = (i + k >= maxi);
        }
        return vector<bool>(nums.begin(), nums.end());
    }
};