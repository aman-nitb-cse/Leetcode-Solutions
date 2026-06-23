// Last updated: 6/24/2026, 3:28:57 AM
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums1, vector<int>& _nums2, vector<vector<int>>& queries) {
        vector<long long> nums2;
        for(int &i : _nums2) nums2.push_back(i);
        unordered_map<int,int> f1;
        for(int &i : nums1) f1[i]++;

        int n = nums2.size();
        int blocks = sqrt(n) + 1;
        vector<long long> adds(blocks);

        vector<unordered_map<int,int>> f2(blocks);

        for(int i = 0; i < n; i++){
            f2[i / blocks][nums2[i]]++;
        }

        vector<int> ans;

        for(auto &q : queries){
            if(q[0] == 1){
                int l = q[1];
                int r = q[2];
                int val = q[3];

                int lb = l / blocks;
                int rb = r / blocks;

                if(lb == rb){
                    for(int i = lb * blocks; i < min(n, (lb + 1) * blocks); i++){
                        nums2[i] += adds[lb];
                    }

                    adds[lb] = 0;
                    f2[lb].clear();
                    for(int i = lb * blocks; i < min(n, (lb + 1) * blocks); i++){
                        if(i >= l && i <= r) nums2[i] += val;

                        f2[lb][nums2[i]]++;
                    }
                }
                else {
                    for(int i = lb * blocks; i < min(n, (lb + 1) * blocks); i++){
                        nums2[i] += adds[lb];
                    }

                    adds[lb] = 0;
                    f2[lb].clear();

                    for(int i = lb * blocks; i < min(n, (lb + 1) * blocks); i++){
                        if(i >= l) nums2[i] += val;

                        f2[lb][nums2[i]]++;
                    }


                    for(int i = rb * blocks; i < min(n, (rb + 1) * blocks); i++){
                        nums2[i] += adds[rb];
                    }

                    adds[rb] = 0;
                    f2[rb].clear();

                    for(int i = rb * blocks; i < min(n, (rb + 1) * blocks); i++){
                        if(i <= r) nums2[i] += val;

                        f2[rb][nums2[i]]++;
                    }

                    for(int b = lb + 1; b < rb; b++) adds[b] += val;
                }
            }
            else {
                int t = q[1];
                long long res = 0;
                for(auto &&[x, f] : f1){
                    int need = t - x;
                    for(int b = 0; b < blocks; b++){
                        res += 1LL * f * f2[b][need - adds[b]];
                    }
                }

                ans.push_back(res);
            }
        }

        return ans;
    }
};
