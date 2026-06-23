// Last updated: 6/24/2026, 3:29:38 AM
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