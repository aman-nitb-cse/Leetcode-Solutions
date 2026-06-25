// Last updated: 6/25/2026, 11:16:46 PM
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        multimap<int, int> m;
        for(int i = 0; i < mat.size(); i++){
            int j;
            for(j = 0; j < mat[0].size() && mat[i][j]; j++);
            m.insert({j, i});
        }

        vector<int> ans;
        for(auto it = m.begin(); it != m.end(); it++){
            if(ans.size() == k) return ans;
            ans.push_back(it->second);
        }
        return ans;
    }
};