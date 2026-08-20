// Last updated: 8/20/2026, 9:20:42 PM
class Solution {
public:
    string convert(string s, int r) {
        if(r == 1) return s;
        vector <string> v(r, "");
        for(int i = 0; i < s.size();){
            for(int j = 0; j < r and i < s.size(); j++) v[j] += s[i++];
            for(int j = r - 2; j and i < s.size(); j--) v[j] += s[i++];
        }

        string ans = "";
        for(string &i : v) ans += i;
        return ans;
    }
};