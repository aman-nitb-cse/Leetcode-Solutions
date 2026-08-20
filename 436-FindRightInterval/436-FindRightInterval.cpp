// Last updated: 8/20/2026, 9:06:02 PM
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& I) {

        int n = I.size();

        for(int i = 0; i < n; i++) I[i].push_back(i);

        ranges::sort(I);

        vector<int> ans(n, -1);

        for(int i = 0; i < n; i++){
            int e = I[i][1], idx = I[i][2];
            

            auto it = ranges::lower_bound(I, vector<int>{e});

            if(it != I.end()) ans[idx] = (*it)[2];
        }

        return ans;
    }
};