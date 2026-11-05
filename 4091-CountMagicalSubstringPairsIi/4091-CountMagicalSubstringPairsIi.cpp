// Last updated: 11/6/2026, 4:30:59 AM
class Solution {
public:
    long long countMagicalPairs(string s) {
        int n = s.size();

        vector<vector<int>> R(n, vector<int>(26));
        vector<vector<int>> L(n, vector<int>(26));
        vector<vector<int>> first(n, vector<int> (26, n));
        vector<vector<int>> last(n, vector<int> (26, -1));

        last[0][s[0] - 'a'] = 0;
        for(int i = 1; i < n; i++){
            last[i] = last[i - 1];
            last[i][s[i] - 'a'] = i;
        }

        first[n - 1][s[n - 1] - 'a'] = n - 1;
        for(int i = n - 2; i >= 0; i--){
            first[i] = first[i + 1];
            first[i][s[i] - 'a'] = i;
        }

        for(int i = 0; i < n; i++){
            vector<int> pos = last[i];
            ranges::sort(pos, greater<int>());

            for(int m = 0; m < 26; m++){
                int curr = pos[m];
                if(curr == -1) break;

                int nxt = (m + 1 < 26) ? pos[m + 1] : -1;
                L[i][m] = curr - nxt;
            }
        }

        for(int i = 0; i < n; i++){
            vector<int> pos = first[i];
            ranges::sort(pos);

            for(int m = 0; m < 26; m++){
                int curr = pos[m];
                if(curr == n) break;

                int nxt = (m + 1 < 26) ? pos[m + 1] : n;
                R[i][m] = nxt - curr;
            }
        }

        long long ans = 0;
        for(int i = 0; i < n - 1; i++){
            for(int d = 0; d < 26; d++){
                ans += 1LL * L[i][d] * R[i + 1][d];
            }
        }

        return ans;
    }
};