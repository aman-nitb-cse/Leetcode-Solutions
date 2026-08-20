// Last updated: 8/20/2026, 8:44:12 PM
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        unordered_map<int,int> freq;
        long long sum = 0, ans = 0;

        for(int i = 0; i < k; i++) {
            freq[nums[i]]++;
            sum += nums[i];
        }

        if(freq.size() == k) ans = max(sum, ans);

        for(int i = k; i < nums.size(); i++) {
            
            freq[nums[i - k]]--;
            sum -= nums[i - k];
            if(freq[nums[i - k]] == 0) freq.erase(nums[i - k]);


            freq[nums[i]]++;
            sum += nums[i];

            if(freq.size() == k) ans = max(sum, ans);
        }

        return ans;
    }
};