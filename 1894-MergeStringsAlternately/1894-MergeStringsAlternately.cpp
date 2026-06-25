// Last updated: 6/25/2026, 11:14:51 PM
class Solution {
public:
    string mergeAlternately(string w1, string w2) {
        string ans = "";
        int n1 = w1.size(), n2 = w2.size();
        int i;
        for(i = 0; i < n2 and i < n1; i++){
            ans += w1[i];
            ans += w2[i];
        }
        if(i == n1) ans += w2.substr(i, n2);
        if(i == n2) ans += w1.substr(i, n1);
        return ans;
    }
};