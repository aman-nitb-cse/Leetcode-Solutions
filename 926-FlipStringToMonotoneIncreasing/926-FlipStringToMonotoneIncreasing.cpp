// Last updated: 11/6/2026, 5:10:41 AM
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int zeros = ranges::count(s,'0');
        int ones = 0;
        int ans = zeros;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1') ones++;
            else zeros--;
            ans = min(ans, ones + zeros);
        }
        return ans;
    }
};