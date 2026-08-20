// Last updated: 8/20/2026, 9:13:31 PM
class Solution {
public:
    unordered_set<string> dict;
    vector<string> ans;
    void solve(string &s, int i = 0, string t = ""){
        if(i == s.size()) ans.push_back(t);

        string temp = "";
        for(int j = i; j < s.size(); j++){
            temp += s[j];
            if(dict.count(temp)){
                if(t == "") solve(s, j + 1, temp);
                else solve(s, j + 1, t + ' ' + temp);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& d) {
        dict.insert(d.begin(), d.end());
        solve(s);
        return ans;
    }
};