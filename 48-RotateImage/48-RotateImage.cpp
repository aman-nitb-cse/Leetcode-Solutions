// Last updated: 8/20/2026, 9:18:01 PM
class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int n = m.size();
        int r = n / 2 - 1 + (n & 1);
        int c = n / 2 - 1;

        for(int r0 = 0; r0 <= r; r0++){
            for(int c0 = 0; c0 <= c; c0++){
                int val = m[r0][c0];

                int r1 = n - c0 - 1;
                int c1 = r0;

                int r2 = n - c1 - 1;
                int c2 = r1;

                int r3 = n - c2 - 1;
                int c3 = r2;

                m[r0][c0] = m[r1][c1];
                m[r1][c1] = m[r2][c2];
                m[r2][c2] = m[r3][c3];
                m[r3][c3] = val;
            }
        }
    }
};