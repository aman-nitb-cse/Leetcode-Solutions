// Last updated: 8/20/2026, 8:39:39 PM
class segTree{
private:
    int n;
    vector<int> seg;

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
public:
    segTree(vector<int>& arr){

        n = arr.size();

        seg.resize(4 * n);

        build(0, 0, n - 1, arr);
    }
    int query(int ql, int qr){
        return query(0, 0, n - 1, ql, qr);
    }
};

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        segTree sqrt(nums);

        int n = nums.size(), ans = INT_MAX;

        for(int i = 0; i < n; i++){
            
            // maximise
            int s = i, e = n - 1;

            while(s <= e){
                int mid = (s + e) >> 1;

                int Or = sqrt.query(i, mid);

                ans = min(ans, abs(Or - k));

                if(Or < k) s = mid + 1;
                else e = mid - 1;
            }

            s = i, e = n - 1;

            while(s <= e){
                int mid = (s + e) >> 1;

                int Or = sqrt.query(i, mid);
                ans = min(ans, abs(Or - k));

                if(Or > k) s = mid + 1;
                else e = mid - 1;
            }
        }

        return ans;
    }
};