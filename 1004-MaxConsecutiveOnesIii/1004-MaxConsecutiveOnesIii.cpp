// Last updated: 11/6/2026, 5:09:13 AM
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int s = 0, e = -1;
        int zeros = 0;

        int ans = 0;

        while(e < n){
            // valid
            if(zeros <= k){
                ans = max(ans, e - s + 1);
                // expand
                e++;
                if(e < n){
                    if(nums[e] == 0) zeros++; 
                }
            }
            // invalid
            else {
                // shrink
                if(nums[s] == 0) zeros--;
                s++;
            }

        }

        return ans;
    }
};