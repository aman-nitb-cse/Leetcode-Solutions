// Last updated: 11/6/2026, 4:49:22 AM
class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {

        vector<int> len(target + 1, -1);

        len[0] = 0;

        for(int &x : nums){

            for(int j = target - x; j >= 0; j--){

                if(len[j] != -1) len[j + x] = max(len[j + x], len[j] + 1);
            }
        }

        return len[target];
    }
};