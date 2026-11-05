// Last updated: 11/6/2026, 4:44:04 AM
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            int next = ((i + nums[i]) % n + n) % n;
            ans[i] = nums[next];
        }
        return ans;
    }
};