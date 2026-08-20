// Last updated: 8/20/2026, 9:18:07 PM
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    vector<bool> isVisited;
    void backtrack(vector<int>& nums){
        if(curr.size() == isVisited.size()){
            ans.push_back(curr);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(isVisited[i] || (i && nums[i] == nums[i - 1] && !isVisited[i - 1])) continue;

            isVisited[i] = true;
            curr.push_back(nums[i]);
            backtrack(nums);

            // undo
            isVisited[i] = false;
            curr.pop_back();

        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        isVisited.assign(nums.size(), false);
        backtrack(nums);
        return ans;
    }
};