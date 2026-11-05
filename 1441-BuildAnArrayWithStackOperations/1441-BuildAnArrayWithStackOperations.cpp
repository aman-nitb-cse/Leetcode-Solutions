// Last updated: 11/6/2026, 5:02:37 AM
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