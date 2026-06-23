// Last updated: 6/24/2026, 3:31:13 AM
class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& BL, vector<vector<int>>& TR) {
        int n = BL.size();

        long long ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {

                long long width = min(TR[i][0], TR[j][0]) - max(BL[i][0], BL[j][0]);

                long long height = min(TR[i][1], TR[j][1]) - max(BL[i][1], BL[j][1]);

                if(width > 0 && height > 0) {
                    long long side = min(width, height);
                    ans = max(ans, side * side);
                }
            }
        }

        return ans;
    }
};