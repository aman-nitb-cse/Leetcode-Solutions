// Last updated: 8/20/2026, 9:12:06 PM
class Solution {
public:
    int rob(vector<int>& nums) {
        int inc = 0, exc = 0;
        for(int &i : nums){
            int temp = exc + i;
            exc = max(inc, exc);
            inc = temp;
        }
        return max(inc, exc);
    }
};