// Last updated: 11/6/2026, 4:34:31 AM
class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> ans(n);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j]){
                    if(i == j) ans[i] += 2;
                    else ans[i]++;
                }
            }
        }
        return ans;
    }
};