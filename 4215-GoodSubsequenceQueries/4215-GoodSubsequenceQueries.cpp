// Last updated: 6/24/2026, 3:28:03 AM
class Solution {
public:

    int countGoodSubseq(vector<int>& nums, int p, vector<vector<int>>& q) {

        int n = nums.size();

        int B = sqrt(n) + 1;

        vector<int> g(B);

        int cnt = 0;

        for(int i = 0; i < n; i++){

            if(nums[i] % p == 0){

                cnt++;

                g[i / B] = gcd(g[i / B], nums[i]);
            }
        }

        int ans = 0;

        for(auto &v : q){

            int idx = v[0], val = v[1];

            if(nums[idx] % p == 0) cnt--;

            if(val % p == 0) cnt++;

            nums[idx] = val;

            int b = idx / B;

            g[b] = 0;

            for(int i = b * B; i < min(n, (b + 1) * B); i++){

                if(nums[i] % p == 0) g[b] = gcd(g[b], nums[i]);

                if(g[b] == p) break;
            }

            int G = 0;

            for(int i = 0; i < B; i++){

                G = gcd(G, g[i]);

                if(G == p) break;
            }

            if(G > p || !cnt) continue;

            if(cnt < n || n >= 7){

                ans++;

                continue;
            }

            for(int i = 0; i < n; i++){

                int gg = 0;

                for(int j = 0; j < n; j++){

                    if(i != j)  gg = gcd(gg, nums[j]);
                }

                if(gg == p){

                    ans++;

                    break;
                }
            }
        }

        return ans;
    }
};