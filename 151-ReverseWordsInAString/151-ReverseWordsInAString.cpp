// Last updated: 8/20/2026, 9:13:00 PM
class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string temp = "";
        while(!s.empty()){
            char c = s.back();
            s.pop_back();
            if(c == ' '){
                if(temp.empty()) continue;
                reverse(temp.begin(), temp.end());
                ans += ' ' + temp;
                temp = "";
            }
            else temp += c;
        }
        reverse(temp.begin(), temp.end());
        ans += ' ' + temp;
        if(ans.front() == ' ') ans.erase(ans.begin());
        if(ans.back() == ' ') ans.pop_back();
        return ans;
    }
};