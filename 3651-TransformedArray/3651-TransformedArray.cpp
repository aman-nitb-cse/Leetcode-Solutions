// Last updated: 6/24/2026, 3:30:11 AM
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