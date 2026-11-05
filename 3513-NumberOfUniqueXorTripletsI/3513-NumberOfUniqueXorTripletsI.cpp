// Last updated: 11/6/2026, 4:42:40 AM
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