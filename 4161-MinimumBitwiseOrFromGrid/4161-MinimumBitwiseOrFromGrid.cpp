// Last updated: 6/24/2026, 3:28:29 AM
class Solution {
public:
    int minimumOR(vector<vector<int>>& g) {
        int m = g.size();
        int n = g[0].size();

        for(int x = 17; x >= 0; x--){
            int mask = (1 << x);
            // can i off this bit
            bool can_off = true;
            for(int i = 0; i < m; i++){
                bool off_found = false;
                for(int j = 0; j < n; j++){
                    // deleted
                    if(g[i][j] == 0) continue;
                    if((mask & g[i][j]) == 0) {
                        off_found = true;
                        break;
                    }
                }
                if(off_found == false) {
                    can_off = false;
                    break;
                }
            }

            if(can_off == false) continue; 

            // set all 0 if msb == 1
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if((mask & g[i][j]) != 0) g[i][j] = 0;
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(g[i][j]) {
                    ans |= g[i][j];
                    break;
                }
            }
        }
        return ans;
    }
};