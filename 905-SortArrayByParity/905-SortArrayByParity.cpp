// Last updated: 11/6/2026, 5:11:05 AM
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        sort(nums.begin(), nums.end(), 
            [](int a, int b){
                return !(a & 1) && (b & 1);
            }
        );
        return nums;
    }
};