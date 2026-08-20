// Last updated: 8/20/2026, 9:18:33 PM
class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, vector<int>& v, int target, int curr = 0){
        if(target == 0){
            ans.push_back(v);
            return;
        }
        if(curr == nums.size() || target < nums[curr]) return;

        // Take 
        v.push_back(nums[curr]);
        solve(nums, v, target - nums[curr], curr + 1);
        v.pop_back();
        
        // Skip
        curr++;
        while (curr < nums.size() && nums[curr] == nums[curr - 1]) curr++;
        solve(nums, v, target, curr);
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> v;
        solve(nums, v, target);
        return ans;
    }
};