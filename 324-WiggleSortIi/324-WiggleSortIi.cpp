// Last updated: 8/20/2026, 9:08:47 PM
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + (nums.size()  + 1)/ 2);
        for(int i = 1; i < nums.size(); i += 2){
            nums.insert(nums.begin() + i, nums.back());
            nums.pop_back();
        }
    }
};