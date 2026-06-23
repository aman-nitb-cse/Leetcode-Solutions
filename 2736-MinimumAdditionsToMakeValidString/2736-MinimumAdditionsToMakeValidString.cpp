// Last updated: 6/24/2026, 3:32:32 AM
class Solution {
public:
    int addMinimum(string s) {
        s = 'c' + s + 'a';
        int ans = 0;
        for(int i = 0; i < s.size() - 1; i++){
            if(s[i] < s[i + 1]) ans += s[i + 1] - s[i] - 1;
            else ans += s[i + 1] - s[i] + 2;
        }
        return ans;
    }
};