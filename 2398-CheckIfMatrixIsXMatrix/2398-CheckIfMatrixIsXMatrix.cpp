// Last updated: 6/25/2026, 11:12:10 PM
class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& a) {
        int n = a.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j or i + j == n - 1) {
                    if(!a[i][j]) return false;
                }
                else if(a[i][j]) return false;
            }
        }
        return true;
    }
};