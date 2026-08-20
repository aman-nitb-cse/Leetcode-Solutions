// Last updated: 8/20/2026, 9:03:46 PM
class Solution {
public:
    bool flag(const string &a, const string &b) {
        if(b.empty()) return true;
        if(a.empty()) return false;

        int i = 0;
        for(char c : a){
            if(i < b.size() && c == b[i]) i++;
        }
        return i == b.size();
    }
    string findLongestWord(string s, vector<string>& d) {
        ranges::sort(d,
            [](auto &a, auto &b){
                if(a.size() == b.size()) return a > b;
                return a.size() < b.size();
            }
        );

        while(!d.empty()){
            string x = d.back(); d.pop_back();
            if(flag(s, x)) return x;
        }
        return "";
    }
};