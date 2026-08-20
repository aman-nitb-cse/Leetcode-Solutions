// Last updated: 8/20/2026, 9:03:47 PM
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> rem;
        int n = nums.size();
        nums[0] %= k;
        if(nums[0]) rem[nums[0]]++;
        for(int i = 1; i < n; i++){
            nums[i] += nums[i - 1];
            nums[i] %= k;
            if(!nums[i]) return true;
            if(nums[i] != nums[i - 1]) rem[nums[i]]++;
            else if(i - 1 && nums[i - 2] == nums[i]) return true;
        }

        for(auto &[key, val] : rem){
            if(val >= 2) return true;
        }
        return false;
    }
};