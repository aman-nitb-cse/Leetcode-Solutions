// Last updated: 6/25/2026, 11:16:27 PM
class Solution {
public:
    int numTeams(vector<int>& R) {
        int n = R.size(), ans = 0;
        for(int i = 0; i < n; i++){
            int cnt[2][2] = {};

            for(int j = 0; j < n; j++){
                if(i ^ j && R[i] ^ R[j]){
                    cnt[i < j][R[i] < R[j]]++;
                }
            }

            ans += cnt[0][0] * cnt[1][1] + cnt[1][0] * cnt[0][1];
        }

        return ans;
    }
};