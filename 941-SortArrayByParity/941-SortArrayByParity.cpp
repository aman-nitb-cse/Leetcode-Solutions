// Last updated: 6/25/2026, 11:19:58 PM
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