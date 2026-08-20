// Last updated: 8/20/2026, 9:04:13 PM
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> v;
        int r = 0, c = 0;
        int x = 1;
        while(v.size() < m * n){
            v.push_back(mat[r][c]);
            r -= x;
            c += x;

            if(r == -1 && c == n){
                x = -1;
                r = 1;
                c = n - 1;
            }
            else if(r == m && c == -1){
                x = 1;
                c = 1;
                r = m - 1;
            }
            else if(r == -1){
                x = -1;
                r = 0;
            }
            else if(r == m){
                x = 1;
                r--;
                c += 2;
            }
            else if(c == -1){
                x = 1;
                c = 0;
            }
            else if(c == n){
                x = -1;
                r += 2;
                c--;
            }
        }
        return v;
    }
};