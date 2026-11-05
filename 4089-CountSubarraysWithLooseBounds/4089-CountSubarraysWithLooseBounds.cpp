// Last updated: 11/6/2026, 4:31:10 AM
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();

        long long ans = 0;
        long long len = 0;

        for(int &i : nums){
            if(i >= minK && i <= maxK){
                len++;
            }
            else {
                ans += len * (len + 1) / 2;
                len = 0;
            }
        }
        ans += len * (len + 1) / 2;
        return ans;
    }
};