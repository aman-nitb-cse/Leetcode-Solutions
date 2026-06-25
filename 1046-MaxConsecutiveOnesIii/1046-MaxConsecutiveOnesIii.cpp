// Last updated: 6/25/2026, 11:18:58 PM
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int s = 0;
        int e = 0;
        int zeros = 1 - nums[0];
        int ans = 0;
        while(e < nums.size()){
            if(zeros > k){ // shrink
                zeros -= 1 - nums[s++];
            }
            else { // expand
                e++;
                ans = max(ans, e - s);
                if(e < nums.size()) zeros += 1 - nums[e];
            }
        }
        return ans;
    }
};