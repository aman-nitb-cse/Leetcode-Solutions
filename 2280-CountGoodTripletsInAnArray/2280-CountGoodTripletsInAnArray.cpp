// Last updated: 6/25/2026, 11:12:45 PM
using bits = bitset<100000>;

class SQRT{
public:

    int n, bs, blocks;

    vector<int> nums;
    vector<bits> B, pref;

    SQRT(vector<int>& arr) : nums(arr){

        n = nums.size();

        bs = sqrt(n);

        blocks = (n + bs - 1) / bs;

        B.resize(blocks);

        for(int i = 0; i < n; i++){
            B[i / bs].set(nums[i]);
        }

        pref.resize(blocks);

        pref[0] = B[0];

        for(int i = 1; i < blocks; i++){
            pref[i] = pref[i - 1] | B[i];
        }
    }

    bits prefixQuery(int r){

        bits res;

        if(r < 0) return res;

        int blk = r / bs;

        if(blk > 0){
            res = pref[blk - 1];
        }

        int start = blk * bs;

        for(int i = start; i <= r; i++){
            res.set(nums[i]);
        }

        return res;
    }
};

class Solution {
public:

    long long goodTriplets(vector<int>& a, vector<int>& b) {

        int n = a.size();

        vector<int> idx(n);

        for(int i = 0; i < n; i++){
            idx[b[i]] = i;
        }

        SQRT B(b);

        bits leftA, rightA;

        for(int x : a){
            rightA.set(x);
        }

        long long ans = 0;

        for(int i = 0; i < n; i++){

            rightA.reset(a[i]);

            bits leftB = B.prefixQuery(idx[a[i]] - 1);

            bits rightB = B.prefixQuery(n - 1);
            rightB ^= B.prefixQuery(idx[a[i]]);

            bits left = leftA & leftB;
            bits right = rightA & rightB;

            ans += 1LL * left.count() * right.count();

            leftA.set(a[i]);
        }

        return ans;
    }
};