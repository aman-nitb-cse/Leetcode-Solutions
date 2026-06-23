// Last updated: 6/24/2026, 3:28:22 AM
class Solution {
public:
    int maxScore(vector<int>& nums, int maxVal) {
        int maxi = max(maxVal, ranges::max(nums));

        vector<int> freq(maxi + 1);
        for(int x : nums) freq[x]++;

        vector<int> cntDiv(maxi + 1);

        for(int d = 1; d <= maxi; d++){
            for(int m = d; m <= maxi; m += d){
                cntDiv[d] += freq[m];
            }
        }

        vector<vector<int>> pf(maxi + 1);

        for(int p = 2; p <= maxi; p++){
            if(pf[p].empty()){
                for(int m = p; m <= maxi; m += p){
                    pf[m].push_back(p);
                }
            }
        }

        int ans = INT_MIN;

        for(int s = 1; s <= maxi; s++){

            int B = 0;

            if(s > 1){
                auto &pr = pf[s];
                int m = pr.size();

                for(int mask = 1; mask < (1 << m); mask++){
                    int prod = 1;
                    int bits = 0;

                    for(int i = 0; i < m; i++){
                        if(mask & (1 << i)){
                            prod *= pr[i];
                            bits++;
                        }
                    }

                    if(bits & 1) B += cntDiv[prod];
                    else B -= cntDiv[prod];
                }
            }

            if(freq[s]){
                if(s == 1) ans = max(ans, 1);
                else ans = max(ans, s - B + 1);
            }

            if(s <= maxVal){
                if(B > 0) ans = max(ans, s - B);
                else ans = max(ans, s - 1);
            }
        }

        return ans;
    }
};