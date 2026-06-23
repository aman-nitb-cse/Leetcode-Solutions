// Last updated: 6/24/2026, 3:31:52 AM
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