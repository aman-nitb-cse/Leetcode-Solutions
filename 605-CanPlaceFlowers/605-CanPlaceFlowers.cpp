// Last updated: 8/20/2026, 9:02:26 PM
class Solution {
public:
    bool canPlaceFlowers(vector<int>& nums, int n) {
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] || (i && nums[i - 1]) || (i + 1 < nums.size() && nums[i + 1])) continue;

            nums[i] = 1;
            n--;
        }
        return n <= 0;
    }
};