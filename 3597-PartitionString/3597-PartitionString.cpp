// Last updated: 11/6/2026, 4:41:47 AM
class Solution {
public:
    vector<string> partitionString(string s) {
        unordered_set<string> st;
        vector<string> ans;
        string temp = "";
        for(char &c : s){
            temp += c;
            if(!st.count(temp)){
                ans.push_back(temp);
                st.insert(temp);
                temp = "";
            }
        }
        return ans;
    }
};