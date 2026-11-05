// Last updated: 11/6/2026, 4:48:57 AM
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& v, char x) {
        vector<int> ans;
        for(int i = 0; i < v.size(); i++){
            int idx = v[i].find(x);
            if(idx < v[i].size() && i >= 0) ans.push_back(i);
        }
        return ans;
    }
};