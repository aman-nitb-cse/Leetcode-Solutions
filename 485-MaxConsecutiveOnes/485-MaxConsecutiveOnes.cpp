// Last updated: 8/20/2026, 9:04:33 PM
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0;
        int i = 0, j = 0;
        while(j < nums.size()){
            if(nums[i] != 1) j = ++i;
            else if(nums[j] == nums[i]) j++;
            else {
                maxi = max(maxi, j - i);
                i = j;
            }
        }
        maxi = max(maxi, j - i);
        return maxi;
    }
};

// class Solution {
// public:
//     int maxPower(string s) {
//         int maxi = 0;
//         int i = 0, j = 0;
//         while(j < s.size()){
//             if(s[j] == s[i]) j++;
//             else {
//                 maxi = max(maxi, j - i);
//                 i = j;
//             }
//         }
//         maxi = max(maxi, j - i);
//         return maxi;
//     }
// };