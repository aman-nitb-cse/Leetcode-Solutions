// Last updated: 8/20/2026, 8:54:58 PM
class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int ans[2] = {};

        for(int p = 0; p < 2; p++){
            for(int i = p; i < nums.size(); i += 2){
                int mn = INT_MAX;

                if(i) mn = min(mn, nums[i - 1]);
                if(i + 1 < nums.size()) mn = min(mn, nums[i + 1]);

                ans[p] += max(0, nums[i] - mn + 1);
            }
        }

        return min(ans[0], ans[1]);
    }
};