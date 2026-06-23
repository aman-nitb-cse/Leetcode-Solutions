// Last updated: 6/24/2026, 3:31:38 AM
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector <vector<int>> ans;
        for(int i = 0; i < n / 3; i++){
            int j = 3 * i;
            if(nums[j + 2] - nums[j] > k) return {};
            // while(j < (i + 1) * 3) ans[i].push_back(nums[j++]);
            ans.push_back(vector <int> (nums.begin() + j, nums.begin() + j + 3));
            
        }
        return ans;
    }
};