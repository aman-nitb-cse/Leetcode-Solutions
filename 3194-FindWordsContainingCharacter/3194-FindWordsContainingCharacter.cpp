// Last updated: 6/24/2026, 3:31:46 AM
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