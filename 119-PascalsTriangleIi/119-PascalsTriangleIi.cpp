// Last updated: 8/20/2026, 9:14:28 PM
class Solution {
public:
    vector<int> getRow(int r) {
        int n = r + 1;
        vector<vector<int>> ans(n);

        for(int i = 0; i < n; i++){
            ans[i].resize(i + 1);
            ans[i].front() = 1;
            ans[i].back() = 1;

            for(int j = 1; j < i; j++){
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
        }
        return ans.back();
    }
};