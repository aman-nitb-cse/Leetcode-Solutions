// Last updated: 11/6/2026, 4:56:58 AM
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans = nums;
        for(int i = 0; i < nums.size(); i++){
            ans.push_back(ans[i]);
        }
        return ans;
    }
};