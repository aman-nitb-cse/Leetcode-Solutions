// Last updated: 8/20/2026, 8:39:14 PM
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if (k == 1) return nums;

        int bad = -1;
        int n = nums.size();

        for(int i = 0; i < k - 1; i++){
            if(nums[i] + 1 != nums[i + 1]){
                bad = i;
            }
        }

        vector<int> ans;
        ans.push_back(bad < 0 ? nums[k - 1] : -1);

        for(int i = k; i < n; i++){
            if(nums[i - 1] + 1 != nums[i]) {
                bad = i - 1;
            }

            ans.push_back(bad <= i - k ? nums[i] : -1);
        }

        return ans;
    }
};