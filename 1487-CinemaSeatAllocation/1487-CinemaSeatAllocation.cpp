// Last updated: 8/20/2026, 8:52:43 PM
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& R) {
        unordered_map<int,bitset<10>> mp;

        for(auto &r : R){
            mp[r[0]].set(r[1] - 1);
        }

        int cnt = 0;

        for(auto& b : mp | views::values){
            // 1 2 3 4
            if(!b[1] && !b[2] && !b[3] && !b[4]){
                cnt++;
                b[1] = b[2] = b[3] = b[4] = 1;
            }


            // 3 4 5 6
            if(!b[3] && !b[4] && !b[5] && !b[6]){
                cnt++;
                b[3] = b[4] = b[5] = b[6] = 1;
            }


            // 5 6 7 8
            if(!b[5] && !b[6] && !b[7] && !b[8]){
                cnt++;
                b[5] = b[6] = b[7] = b[8] = 1;
            }
        }

        return cnt + 2 * (n - mp.size());
    }
};