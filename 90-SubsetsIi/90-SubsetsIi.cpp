// Last updated: 8/20/2026, 9:15:57 PM
class Solution {
public:
    vector<vector<int>> ans = {{}};
    vector<int> curr;

    void solve(vector<int>& nums, int i = 0){
        if(i == nums.size()) return;

        // take 
        curr.push_back(nums[i]);
        ans.push_back(curr);
        solve(nums, ++i);
        curr.pop_back();

        // skip
        while(i < nums.size() && nums[i] == nums[i - 1]) i++;
        solve(nums, i);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        solve(nums);
        return ans;
    }
};