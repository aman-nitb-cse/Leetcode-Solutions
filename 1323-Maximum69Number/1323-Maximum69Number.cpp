// Last updated: 11/6/2026, 5:04:32 AM
class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        int i = s.find('6');
        if(i != -1) s[i] = '9';
        return stoi(s);
    }
};