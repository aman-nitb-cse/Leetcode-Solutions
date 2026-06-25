// Last updated: 6/25/2026, 11:37:28 PM
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int maxi = 0;
        nums.push_back(INT_MIN);
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[j] <= nums[j - 1]){
                    maxi = max(maxi, j - i);
                    i = j - 1;
                    break;
                }
            }
        }
        return maxi;
    }
};