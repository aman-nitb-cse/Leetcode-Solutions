// Last updated: 6/25/2026, 11:20:32 PM
class segTree{
public:
    int n;
    vector<long long> seg;
    vector<long long>& pref;

    segTree(vector<long long>& arr) : pref(arr){

        n = pref.size();

        seg.resize(4 * n);

        build(0, 0, n - 1);
    }

    void build(int idx, int l, int r){

        if(l == r){
            seg[idx] = pref[l];
            return;
        }

        int m = (l + r) / 2;

        build(idx * 2 + 1, l, m);
        build(idx * 2 + 2, m + 1, r);

        seg[idx] = min(seg[idx * 2 + 1], seg[idx * 2 + 2]);
    }

    int query(int idx, int l, int r, int qr, long long target){

        if(l > qr || seg[idx] > target)
            return -1;

        if(l == r)
            return l;

        int m = (l + r) / 2;

        int ans = query(idx * 2 + 2, m + 1, r, qr, target);

        if(ans != -1) return ans;

        return query(idx * 2 + 1, l, m, qr, target);
    }
};

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {

        int n = nums.size();

        vector<long long> pref(n + 1);

        for(int i = 0; i < n; i++){
            pref[i + 1] = pref[i] + nums[i];
        }

        segTree root(pref);

        int ans = INT_MAX;

        for(int j = 1; j <= n; j++){

            int i = root.query(
                0,
                0,
                n,
                j - 1,
                pref[j] - k
            );

            if(i != -1){
                ans = min(ans, j - i);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};