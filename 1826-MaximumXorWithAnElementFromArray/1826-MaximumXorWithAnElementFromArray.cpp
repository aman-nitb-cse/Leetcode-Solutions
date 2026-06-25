// Last updated: 6/25/2026, 11:15:11 PM
class Tries {
public:
    Tries* bit[2] = {NULL};

    void insert(int x, int i = 31){
        if(i < 0) return;
        int b = (x >> i) & 1;
        if(bit[b] == NULL) bit[b] = new Tries();
        bit[b]->insert(x, i - 1);
    }

    int Xor(int x, int i = 31){
        if(i < 0) return 0;
        int x_bit = (x >> i) & 1;
        int want = !x_bit;
        if(bit[want]) return (1 << i) + bit[want]->Xor(x, i - 1);
        return bit[!want]->Xor(x, i - 1);
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& q) {
        sort(nums.begin(), nums.end());

        int n = q.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b){
            return q[a][1] < q[b][1];
        });

        auto node = new Tries();
        vector<int> ans(n);
        int ni = 0;

        for(auto i : idx){
            int x = q[i][0], m = q[i][1];
            while(ni < (int)nums.size() && nums[ni] <= m)
                node->insert(nums[ni++]);
            ans[i] = (ni == 0) ? -1 : node->Xor(x);
        }
        return ans;
    }
};