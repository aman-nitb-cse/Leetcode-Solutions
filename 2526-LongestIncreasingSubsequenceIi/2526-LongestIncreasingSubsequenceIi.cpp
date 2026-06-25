// Last updated: 6/25/2026, 11:11:33 PM
class segTree{
private:
    int n;
    vector<int> seg;

    void update(int idx, int l, int r, int pos, int val){

        if(l == r){
            seg[idx] = max(seg[idx], val);
            return;
        }

        int m = (l + r) / 2;

        if(pos <= m)
            update(idx * 2 + 1, l, m, pos, val);
        else
            update(idx * 2 + 2, m + 1, r, pos, val);

        seg[idx] = max(
            seg[idx * 2 + 1],
            seg[idx * 2 + 2]
        );
    }

    int query(int idx, int l, int r, int ql, int qr){

        if(qr < l || r < ql)
            return 0;

        if(ql <= l && r <= qr)
            return seg[idx];

        int m = (l + r) / 2;

        return max(
            query(idx * 2 + 1, l, m, ql, qr),
            query(idx * 2 + 2, m + 1, r, ql, qr)
        );
    }

public:

    segTree(int n) : n(n){
        seg.resize(4 * n);
    }

    void update(int pos, int val){
        update(0, 0, n - 1, pos, val);
    }

    int query(int l, int r){

        if(l > r)
            return 0;

        return query(0, 0, n - 1, l, r);
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {

        segTree seg(100001);

        int ans = 0;

        for(int i : nums | views::reverse){

            int dp = 1 + seg.query(i + 1, min(100000, i + k));

            seg.update(i, dp);

            ans = max(ans, dp);
        }

        return ans;
    }
};