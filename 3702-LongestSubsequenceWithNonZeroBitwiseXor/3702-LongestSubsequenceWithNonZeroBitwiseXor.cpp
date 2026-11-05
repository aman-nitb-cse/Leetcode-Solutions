// Last updated: 11/6/2026, 4:39:55 AM
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x = 0;

        int n = nums.size();

        bool non_zero = false;

        for(int &i : nums) {
            x ^= i;
            if(i) non_zero = true;
        }

        if(!non_zero) return 0;

        return n - !x;
    }
};