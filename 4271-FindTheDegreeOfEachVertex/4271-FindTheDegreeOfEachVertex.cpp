// Last updated: 6/24/2026, 3:27:17 AM
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