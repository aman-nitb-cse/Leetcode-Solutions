// Last updated: 8/20/2026, 9:17:43 PM
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector <int> v; 
        int loops = 0;
        while(v.size() < m * n){
            for(int i = loops; i < n - loops; i++){
                v.push_back(matrix[loops][i]);
            }
            for(int i = loops + 1; i < m - loops; i++){
                v.push_back(matrix[i][n - loops - 1]);
            }
            for(int i = n - loops - 2; i >= loops; i--){
                v.push_back(matrix[m - loops - 1][i]);
            }
            for(int i = m - loops - 2; i > loops; i--){
                v.push_back(matrix[i][loops]);
            }
            loops++;
        }
        v.resize(m * n);
        return v;
    }
};