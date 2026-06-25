// Last updated: 6/25/2026, 11:16:08 PM
class Solution {
public:
    vector<string> buildArray(vector<int>& nums, int n) {
        vector<string> ans;

        for(int i = 1, j = 0; i <= n && j < nums.size(); i++){
            ans.push_back("Push");
            if(i != nums[j]) ans.push_back("Pop");
            else j++;
        }
        return ans;
    }
};