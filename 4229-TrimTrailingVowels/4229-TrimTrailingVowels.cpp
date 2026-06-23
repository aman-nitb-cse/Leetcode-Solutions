// Last updated: 6/24/2026, 3:27:51 AM
class Solution {
public:
    string trimTrailingVowels(string s) {
        if(s.empty()) return s;
        char &c = s.back();
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            s.pop_back();
            return trimTrailingVowels(s);
        }
        return s;
    }
};