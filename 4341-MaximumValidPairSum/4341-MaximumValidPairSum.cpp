// Last updated: 7/6/2026, 5:33:56 AM
class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> suf = nums;

        for(int i = n - 2; i >= 0; i--){
            suf[i] = max(suf[i], suf[i + 1]);
        }

        int pref = INT_MIN, ans = INT_MIN;

        for(int i = 0; i + k < n; i++){
            pref = max(pref, nums[i]);

            ans = max(ans, pref + suf[i + k]);
        }

        return ans;
    }
};