// Last updated: 6/24/2026, 3:31:01 AM
class segTree{
public:
    int n;
    vector<int> seg;

    segTree(vector<int>& arr){

        n = arr.size();

        seg.resize(4 * n);

        build(0, 0, n - 1, arr);
    }

    void build(int idx, int l, int r, vector<int>& arr){

        if(l == r){
            seg[idx] = arr[l];
            return;
        }

        int m = (l + r) / 2;

        build(idx * 2 + 1, l, m, arr);

        build(idx * 2 + 2, m + 1, r, arr);

        seg[idx] = seg[idx * 2 + 1] | seg[idx * 2 + 2];
    }

    // idx : index of root node
    // [l, r] : range of root node
    // [ql, qr] : range of query
    int query(int idx, int l, int r, int ql, int qr){

        // no overlap [l, r] ∩ [ql, qr] = ɸ
        if(qr < l || ql > r) return 0;

        // complete overlap  [l, r] ∈ [ql, qr] 
        if(ql <= l && r <= qr) return seg[idx];

        // partial overlap
        int m = (l + r) / 2;

        return query(idx * 2 + 1, l, m, ql, qr) | query(idx * 2 + 2, m + 1, r, ql, qr);
    }
};

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {

        segTree root(nums);

        int s = 0, e = 0, n = nums.size(), ans = INT_MAX;

        while(e < n && s <= e){

            // shrink
            if(root.query(0, 0, n - 1, s, e) >= k) {
                ans = min(ans, e - s + 1);
                s++;
            }
            else e++;
        }

        return ans < INT_MAX ? ans : -1;
    }
};