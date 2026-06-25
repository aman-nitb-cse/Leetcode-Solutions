// Last updated: 6/25/2026, 11:20:23 PM
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int t = m - n;
        if(t > 0){
            for(int i = 0; i < m; i++){
                matrix[i].resize(m);
            }
        }
        else if(t < 0){
            for(int i = 0; i < -t; i++){
                matrix.push_back(vector <int> (n));
            }
        }
        int size = max(m, n);
        for(int i = 0; i < size; i++){
            for(int j = i + 1; j < size; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        if(t > 0){
            matrix.resize(n);
        }
        else if(t < 0){
            for(int i = 0; i < size; i++){
                matrix[i].resize(m);
            }
        }
        return matrix;
    }
};