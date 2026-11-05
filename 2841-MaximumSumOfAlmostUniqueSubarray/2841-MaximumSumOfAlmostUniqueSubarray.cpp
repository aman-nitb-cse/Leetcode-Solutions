// Last updated: 11/6/2026, 4:49:51 AM
class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        int n = nums.size();

        unordered_map<int,int> freq;

        long long sum = 0;

        for(int i = 0; i < k; i++){
            freq[nums[i]]++;
            sum += nums[i];
        }

        long long ans = 0;

        if(freq.size() >= m) ans = max(ans, sum);

        for(int i = k; i < n; i++){
            sum += nums[i] - nums[i - k];
            freq[nums[i]]++;
            freq[nums[i - k]]--;
            if(freq[nums[i - k]] == 0) freq.erase(nums[i - k]);
            if(freq.size() >= m) ans = max(ans, sum);
        }
        return ans;
    }
};