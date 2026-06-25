// Last updated: 6/25/2026, 11:16:15 PM
class Solution {
public:
    int maxPower(string s) {
        int maxi = 0;
        int i = 0, j = 0;
        while(j < s.size()){
            if(s[j] == s[i]) j++;
            else {
                maxi = max(maxi, j - i);
                i = j;
            }
        }
        maxi = max(maxi, j - i);
        return maxi;
    }
};