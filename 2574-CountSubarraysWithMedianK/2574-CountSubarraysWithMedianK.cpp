// Last updated: 6/25/2026, 11:11:11 PM
class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int index = ranges::find(nums, k) - nums.begin(), n = nums.size();
        
        vector<int> diff(n);
        unordered_map<int,int> cnt;

        cnt[0] = 1;

        for(int i = index - 1; i >= 0; i--){
            diff[i] += (nums[i] > k) - (nums[i] < k) + diff[i + 1];
            cnt[diff[i]]++;
        }

        for(int i = index + 1; i < n; i++){
            diff[i] += (nums[i] > k) - (nums[i] < k) + diff[i - 1];
        }

        int ans = 0;

        for(int i = index; i < n; i++){
            ans += cnt[-diff[i]] + cnt[1 - diff[i]];
        }

        return ans;
    }
};