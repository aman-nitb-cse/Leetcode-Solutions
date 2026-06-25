// Last updated: 6/25/2026, 11:14:29 PM
class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& R) {

        R.push_back({1, 0});

        ranges::sort(R);

        int m = R.size();

        // left -> right
        for(int i = 1; i < m; i++){
            R[i][1] = min(
                R[i][1],
                R[i - 1][1] + (R[i][0] - R[i - 1][0])
            );
        }

        // right -> left
        for(int i = m - 2; i >= 0; i--){
            R[i][1] = min(
                R[i][1],
                R[i + 1][1] + (R[i + 1][0] - R[i][0])
            );
        }

        int ans = 0;

        for(int i = 1; i < m; i++){

            int x = R[i][0] - R[i - 1][0];
            int y = abs(R[i][1] - R[i - 1][1]);

            ans = max(
                ans,
                max(R[i][1], R[i - 1][1]) + (x - y) / 2
            );
        }

        // after last restriction to building n
        ans = max(
            ans,
            R.back()[1] + (n - R.back()[0])
        );

        return ans;
    }
};