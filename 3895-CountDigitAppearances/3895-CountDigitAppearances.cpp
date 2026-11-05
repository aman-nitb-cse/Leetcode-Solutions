// Last updated: 11/6/2026, 4:34:10 AM
class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int d) {
        int ans = 0;
        for(int &i : nums){
            string s = to_string(i);
            ans += ranges::count(s, d + '0');
        }
        return ans;
    }
};