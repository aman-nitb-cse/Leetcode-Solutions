// Last updated: 6/30/2026, 2:24:19 PM
class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& I, int fs, int fe) {
        ranges::sort(I);
        int ps = I[0][0], pe = I[0][0];

        vector<vector<int>> ans;

        auto push = [&](){
            if(ps > fe || pe < fs){
                ans.push_back({ps, pe});
            }
            else {
                if(ps <= fs - 1) ans.push_back({ps, fs - 1});
                if(fe + 1 <= pe) ans.push_back({fe + 1, pe});
            }
        };

        for(auto &v : I){
            int cs = v[0], ce = v[1];

            // overlap
            if(pe + 1 >= cs) pe = max(pe, ce);
            // non overlap
            else {
                // push [ps, pe]
                
                push();

                ps = cs;
                pe = ce;
            }
        }

        push();

        return ans;
    }
};