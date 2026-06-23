// Last updated: 6/24/2026, 3:31:45 AM
class Solution {
public:
    long long countSubarrays(vector<int> &nums, int k) {
        int maxi = *max_element(nums.begin(), nums.end());
        int size = nums.size();
        int new_size = 0;
        for(int i = 0; i < size; i++){
            if(nums[i] == maxi) nums[new_size++] = i;
        }
        nums.resize(new_size);
        long long ans = 0;
        for(int i = 0; i <= new_size - k; i++){
            int s = i, e = i + k - 1;

            long long x = nums[s] + 1, y = size - nums[e];
		    if(s) x = nums[s] - nums[s - 1];		
            ans += x * y;
            s++;
        }
        
        return ans;
    }
};