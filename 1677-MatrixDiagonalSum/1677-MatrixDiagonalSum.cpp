// Last updated: 6/25/2026, 11:15:40 PM
class Solution {
public:
    int diagonalSum(vector<vector<int>>& a) {
        int sum = 0, n = a.size();
        for(int i = 0; i < n; i++){
            sum += a[i][i] + a[i][n - i - 1];
        }
        return sum - a[n/2][n/2] * (n & 1);
    }
};