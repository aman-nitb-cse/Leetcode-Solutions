// Last updated: 6/25/2026, 11:14:03 PM
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int s = 0, e = m - 1;
        while(s <= e){
            int i = s + (e - s) / 2;
            auto &v = mat[i];
            int peak = 0;
            for(auto [j, x] : views::enumerate(v)){
                if(x > v[peak]) peak = j;
            }

            if(i + 1 < m && v[peak] < mat[i + 1][peak]){ // move down
                s = i + 1;
            }
            else if(i && v[peak] < mat[i - 1][peak]){  // move up
                e = i - 1;
            }
            else return {i, peak};
        }
        return {};
    }
};