// Last updated: 6/25/2026, 11:16:18 PM
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