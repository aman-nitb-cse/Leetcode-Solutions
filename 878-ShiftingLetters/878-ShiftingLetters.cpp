// Last updated: 6/25/2026, 11:20:35 PM
class Solution {
public:
    string shiftingLetters(string s, vector<int>& sh) {
        int n = s.size();
        int next = 0;
        for(int i = n - 1; i >= 0; i--) {
            sh[i] += next;
            sh[i] %= 26;
            next = sh[i];
        }

        for(auto&& [c, x] : views::zip(s, sh)){
            c = (c - 'a' + x) % 26 + 'a';
        }
        return s;
    }
};