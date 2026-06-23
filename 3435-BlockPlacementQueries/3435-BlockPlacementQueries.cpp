// Last updated: 6/24/2026, 3:30:47 AM
class Solution {
public:
    int n;
    vector<array<int,4>> seg; // {left, right, max, count of obs}

    void build(int idx, int l, int r){

        if(l == r){
            seg[idx] = {0, 0, 0, 0};
            return;
        }

        int m = (l + r) / 2;

        build(idx * 2 + 1, l, m);

        build(idx * 2 + 2, m + 1, r);

        calc(idx);
    }

    void calc(int idx){
        auto& left = seg[idx * 2 + 1];
        auto& right = seg[idx * 2 + 2];
        auto& curr = seg[idx];

        curr[0] = left[0];
        curr[1] = right[1];

        if(left[3] == 0) curr[0] += right[0] + 1;
        if(right[3] == 0) curr[1] += left[1] + 1;

        curr[2] = max({
            curr[0],
            curr[1],
            left[1] + right[0] + 1,
            max(left[2], right[2])
        });

        curr[3] = left[3] + right[3];
    }

    void update(int idx, int l, int r, int x){

        if(l == r){
            seg[idx] = {0, 0, 0, 1};
            return;
        }

        int m = (l + r) >> 1;

        if(x <= m) update(idx * 2 + 1, l, m, x);
        else update(idx * 2 + 2, m + 1, r, x);

        calc(idx);
    }

    // idx : index of root node
    // [l, r] : range of root node
    // [ql, qr] : range of query
    bool query(int idx, int l, int r, int x, int sz, int left = -1){

        // cout << l << ' ' << r << endl;

        // no overlap [l, r] ∩ [ql, qr] = ɸ
        if(x < l) return false;

        // complete overlap  [l, r] ∈ [ql, qr] 
        if(r <= x) return max(left + seg[idx][0] + 1, seg[idx][2]) >= sz;

        // partial overlap
        int m = (l + r) >> 1;

        int _left = seg[idx * 2 + 1][1];
        if(seg[idx * 2 + 1][3] == 0) _left += left + 1;
        return query(idx * 2 + 1, l, m, x, sz, left) || query(idx * 2 + 2, m + 1, r, x, sz, _left);
    }

    void print(int idx, int l, int r){
        int m = (l + r) >> 1;
        if(l ^ r){
            print(2 * idx + 1, l, m);
            print(2 * idx + 2, m + 1, r);
        }


        // cout << l << ' ' << r << " : ";
        // for(int &i : seg[idx]) cout << i << ' ';
        // cout << endl;
    }

    vector<bool> getResults(vector<vector<int>>& queries) {
        n = 1 + min(3 * (int)queries.size(), 50000);

        seg.resize(4 * n);

        build(0, 0, n - 1);

        vector<bool> ans;

        for(auto &q : queries){
            if(q[0] == 1) update(0, 0, n - 1, q[1]);
            else ans.push_back(query(0, 0, n - 1, q[1], q[2]));
        }

        // cout << "\n\n\n";

        // print(0, 0, n - 1);

        return ans;
    }
};