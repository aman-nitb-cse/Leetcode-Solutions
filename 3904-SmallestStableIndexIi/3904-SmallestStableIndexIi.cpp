// Last updated: 11/6/2026, 4:33:55 AM
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int ans = INT_MAX;
        vector<int> mini(nums.size());

        int _mini = INT_MAX;
        for(int i = nums.size() - 1; i >= 0; i--){
            _mini = min(_mini, nums[i]);
            mini[i] = _mini;
        }

        int _maxi = INT_MIN;

        for(int i = 0; i < nums.size(); i++){
            _maxi = max(_maxi, nums[i]);
            int diff = _maxi - mini[i];

            if(diff <= k) ans = min(ans, i);
        }

        return ans < INT_MAX ? ans : -1;
    }
};