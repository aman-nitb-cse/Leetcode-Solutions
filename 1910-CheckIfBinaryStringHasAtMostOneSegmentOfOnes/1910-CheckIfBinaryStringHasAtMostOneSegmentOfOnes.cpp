// Last updated: 6/25/2026, 11:14:46 PM
class Solution {
public:
    bool checkOnesSegment(string s) {
        bool flag = false;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0') continue;
            int j;
            for(j = i + 1; j < s.size() and s[j] == '1'; j++);
            if(j - i){
                if(flag) return false;
                flag = true;
            }
            i = j;
        }
        return true;
    }
};