// Last updated: 11/6/2026, 5:06:21 AM
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& nums) {

        int n = nums.size();

        vector<int> ans(n);

        vector<int> dp;

        for(int i = n - 1; i >= 0; i--){

            int count = 0;
            while(!dp.empty() && nums[i] >= dp.back()) {
                dp.pop_back();
                count++;
            }
            dp.push_back(nums[i]);

            ans[i] = count + (dp.size() > 1);
        }

        return ans;
    }
};