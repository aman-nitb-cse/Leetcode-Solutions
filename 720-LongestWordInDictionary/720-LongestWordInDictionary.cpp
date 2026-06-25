// Last updated: 6/25/2026, 11:36:57 PM
class Solution {
public:
    string longestWord(vector<string>& w) {
        unordered_set<string> st(w.begin(), w.end());

        sort(w.begin(), w.end(), 
            [](auto &a, auto &b){
                if(a.size() == b.size()) return a < b;
                return a.size() > b.size();
            }
        );

        for(string &s : w){
            bool valid = true;
            auto temp = s;
            temp.pop_back();
            while(!temp.empty()){
                if(!st.count(temp)) {
                    valid = false;
                    break;
                }
                temp.pop_back();
            }
            if(valid) return s;
        }
        return "";
    }
};