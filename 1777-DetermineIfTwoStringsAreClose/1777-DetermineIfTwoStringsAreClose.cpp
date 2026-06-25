// Last updated: 6/25/2026, 11:15:22 PM
class Solution {
public:
    bool closeStrings(string a, string b) {
        if(a.size() != b.size()) return false;

        vector<int> _a(26), _b(26);

        for(char &i : a) _a[i - 'a']++;
        for(char &i : b) _b[i - 'a']++;

        for(int i = 0; i < 26; i++){
            if((_a[i] == 0 && _b[i] != 0) || (_a[i] != 0 && _b[i] == 0)) return false;
        }

        ranges::sort(_a);
        ranges::sort(_b);
        return _a == _b;
    }
};