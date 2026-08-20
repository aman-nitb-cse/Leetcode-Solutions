// Last updated: 8/20/2026, 9:09:55 PM
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int num = n * (n + 1) / 2;
        for(int &i : nums) num -= i;
        return num;
    }
};