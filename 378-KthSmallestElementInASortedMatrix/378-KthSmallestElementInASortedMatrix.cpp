// Last updated: 8/20/2026, 9:07:25 PM
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {

        int n = mat.size();
        int s = mat[0][0], e = mat[n-1][n-1];

        while(s < e){

            int mid = s + (e-s)/2;
            int count = 0;

            for(auto &row : mat)
                count += ranges::upper_bound(row, mid) - row.begin();

            if(count < k)
                s = mid + 1;
            else
                e = mid;
        }

        return s;
    }
};