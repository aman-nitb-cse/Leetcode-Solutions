// Last updated: 6/24/2026, 3:29:04 AM
class SQRT{
public:

    static constexpr int SHIFT = 100000;

    int n, bs, blocks;

    vector<int> nums, lazy;
    vector<bitset<200001>> B;

    SQRT(int n) : n(n){

        bs = sqrt(n);

        blocks = (n + bs - 1) / bs;

        nums.resize(n);
        lazy.resize(blocks);

        B.resize(blocks);

        for(int b = 0; b < blocks; b++){
            rebuild(b);
        }
    }

    void rebuild(int b){

        B[b].reset();

        int l = b * bs;
        int r = min(n, (b + 1) * bs);

        for(int i = l; i < r; i++){
            B[b].set(nums[i] + SHIFT);
        }
    }

    void update(int l, int r, int val){

        if(l > r) return;

        int lb = l / bs;
        int rb = r / bs;

        if(lb == rb){

            int L = lb * bs;
            int R = min(n, (lb + 1) * bs);

            for(int i = L; i < R; i++){
                nums[i] += lazy[lb];
            }

            lazy[lb] = 0;

            for(int i = l; i <= r; i++){
                nums[i] += val;
            }

            rebuild(lb);

            return;
        }

        int L = lb * bs;
        int R = min(n, (lb + 1) * bs);

        for(int i = L; i < R; i++){
            nums[i] += lazy[lb];
        }

        lazy[lb] = 0;

        for(int i = l; i < R; i++){
            nums[i] += val;
        }

        rebuild(lb);

        L = rb * bs;
        R = min(n, (rb + 1) * bs);

        for(int i = L; i < R; i++){
            nums[i] += lazy[rb];
        }

        lazy[rb] = 0;

        for(int i = L; i <= r; i++){
            nums[i] += val;
        }

        rebuild(rb);

        for(int b = lb + 1; b < rb; b++){
            lazy[b] += val;
        }
    }

    int query(int r){

        for(int b = 0; b <= r / bs; b++){

            int need = SHIFT - lazy[b];

            if(need < 0 || need > 200000)
                continue;

            if(!B[b][need])
                continue;

            int l = b * bs;
            int rr = min(n, (b + 1) * bs);

            for(int i = l; i < rr; i++){

                if(i > r) break;

                if(nums[i] + lazy[b] == 0){
                    return i;
                }
            }
        }

        return -1;
    }
};

class Solution {
public:
    int longestBalanced(vector<int>& nums) {

        int n = nums.size();

        SQRT sq(n);

        vector<int> pos(100001, -1);

        int ans = 0;

        for(int i = 0; i < n; i++){

            int val = (nums[i] & 1) ? -1 : 1;

            int l = pos[nums[i]] + 1;

            pos[nums[i]] = i;

            sq.update(l, i, val);

            int k = sq.query(i);

            if(k != -1){
                ans = max(ans, i - k + 1);
            }
        }

        return ans;
    }
};