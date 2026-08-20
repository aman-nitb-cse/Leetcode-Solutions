// Last updated: 8/20/2026, 9:16:37 PM
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    void backtrack(vector<int>& nums, int i = 0){
        if(i == nums.size()) {
            ans.push_back(curr);
            return;
        }

        // skip
        backtrack(nums, i + 1);

        // take
        curr.push_back(nums[i]);
        backtrack(nums, i + 1);
        curr.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums);
        return ans;
    }
};