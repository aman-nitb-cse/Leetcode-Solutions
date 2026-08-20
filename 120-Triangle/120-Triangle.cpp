// Last updated: 8/20/2026, 9:14:27 PM
class Solution {
public:
    int minimumTotal(vector<vector<int>>& v) {
        for(int i = v.size() - 2; i >= 0; i--){
            for(int j = 0; j < v[i].size(); j++){
                v[i][j] += min(v[i + 1][j], v[i + 1][j + 1]);
            }
        }
        return v[0][0];
    }
};