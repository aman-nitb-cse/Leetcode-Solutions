// Last updated: 11/6/2026, 5:21:24 AM
class Solution {
public:
    vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;

    void solve(string &s, int i = 0, string st = "") {
        if (i == s.size()) {
            ans.push_back(st);
            return;
        }
        string& temp = v[s[i] - '0'];
        for (char& c : temp) {
            solve(s, i + 1, st + c);
        }
    }

    vector<string> letterCombinations(string s) {
        if(s.empty()) return {};
        ans.clear();
        solve(s);
        return ans;
    }
};