// Last updated: 6/25/2026, 11:16:52 PM
class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        int i = s.find('6');
        if(i != -1) s[i] = '9';
        return stoi(s);
    }
};