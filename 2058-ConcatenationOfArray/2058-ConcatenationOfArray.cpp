// Last updated: 6/25/2026, 11:14:00 PM
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