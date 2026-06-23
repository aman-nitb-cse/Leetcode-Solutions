// Last updated: 6/24/2026, 3:31:42 AM
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& v) {
        vector<int> nums;
        for(int i = 0; i < v.size(); i++){
            for(int j = 0; j < v[0].size(); j++){
                nums.push_back(v[i][j]);
            }
        }
        vector<int> ans(2);
        sort(nums.begin(), nums.end()); 
        int sum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i - 1]) ans[0] = nums[i];
            else sum += nums[i];
        }
        int n = nums.size();
        ans[1] = n * (n + 1) / 2 - sum;

        return ans;
    }
};