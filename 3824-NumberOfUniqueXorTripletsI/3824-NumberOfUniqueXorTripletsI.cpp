// Last updated: 8/20/2026, 8:37:04 PM
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2)  return n;


        int ans = 1;
        while (ans <= n) {
            ans <<= 1;
        }
        
        return ans;
    }
};