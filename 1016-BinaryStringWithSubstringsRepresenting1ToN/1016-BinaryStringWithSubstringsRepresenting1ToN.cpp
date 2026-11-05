// Last updated: 11/6/2026, 5:08:56 AM
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