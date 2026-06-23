// Last updated: 6/24/2026, 3:26:56 AM
class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        if(nums.size() < 3) return nums;
        vector<int> ans = {nums[0]};
        multiset<int> st(nums.begin() + 2, nums.end());

        int left = nums[0];
        for(int i = 1; i < nums.size() - 1; i++){
            if(nums[i] > min(left, *st.rbegin())) ans.push_back(nums[i]);

            left = max(left, nums[i]);
            if(i + 1 < nums.size()) st.erase(st.find(nums[i + 1]));
        }
        ans.push_back(nums.back());
        return ans;
    }
};