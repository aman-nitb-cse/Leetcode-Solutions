// Last updated: 6/24/2026, 3:29:11 AM
class segTree{
public:
    int n;
    vector<array<int,2>> seg;

    segTree(vector<int>& arr){

        n = arr.size();

        seg.resize(4 * n);

        build(0, 0, n - 1, arr);
    }

    void build(int idx, int l, int r, vector<int>& arr){

        if(l == r){
            seg[idx] = {arr[l], arr[l]};
            return;
        }

        int m = (l + r) / 2;

        build(idx * 2 + 1, l, m, arr);

        build(idx * 2 + 2, m + 1, r, arr);

        seg[idx] = {
            min(seg[idx * 2 + 1][0], seg[idx * 2 + 2][0]),
            max(seg[idx * 2 + 1][1], seg[idx * 2 + 2][1])
        };
    }

    // idx : index of root node
    // [l, r] : range of root node
    // [ql, qr] : range of query
    int get_min(int idx, int l, int r, int ql, int qr){

        // no overlap [l, r] ∩ [ql, qr] = ɸ
        if(qr < l || ql > r) return INT_MAX;

        // complete overlap  [l, r] ∈ [ql, qr] 
        if(ql <= l && r <= qr) return seg[idx][0];

        // partial overlap
        int m = (l + r) / 2;

        return min(get_min(idx * 2 + 1, l, m, ql, qr), get_min(idx * 2 + 2, m + 1, r, ql, qr));
    }
    int get_max(int idx, int l, int r, int ql, int qr){

        // no overlap [l, r] ∩ [ql, qr] = ɸ
        if(qr < l || ql > r) return INT_MIN;

        // complete overlap  [l, r] ∈ [ql, qr] 
        if(ql <= l && r <= qr) return seg[idx][1];

        // partial overlap
        int m = (l + r) / 2;

        return max(get_max(idx * 2 + 1, l, m, ql, qr), get_max(idx * 2 + 2, m + 1, r, ql, qr));
    }

    int query(int l, int r){
        return get_max(0, 0, n - 1, l, r) - get_min(0, 0, n - 1, l, r);
    }
};

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        segTree root(nums);

        int n = nums.size();

        // cout << root.query(0, 2);
        priority_queue<array<int,3>> pq;
        unordered_set<long long> vis;

        pq.push({root.query(0, n - 1), 0, n - 1});

        long long ans = 0;

        while(k-- && !pq.empty()){
            auto [d, l, r] = pq.top(); pq.pop();

            ans += d;

            pair<int,int> nxt[] = {{l+1, r}, {l, r-1}};

            for(auto [nl, nr] : nxt){
                long long key = (long long) nl << 32 | nr;
                if(nl <= nr && nl < n && nl >= 0 && nr < n && nr >= 0 && !vis.count(key)){
                    pq.push({root.query(nl, nr), nl, nr});
                    vis.insert(key);
                }
            }
        }

        return ans;
    }
};