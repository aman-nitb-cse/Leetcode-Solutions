// Last updated: 6/25/2026, 11:18:49 PM
class Solution {
public:
    bool queryString(string s, int n) {
        int i = 0;
        while(i < s.size() && s[i] == '0') i++;
        s = s.substr(i);
        while(n){
            string temp = "";
            for(int j = n--; j; j >>= 1){
                temp.push_back((j&1) + '0');
            }
            reverse(temp.begin(), temp.end());
            if(s.find(temp) == string::npos) return false;
        }
        return true;
    }
};