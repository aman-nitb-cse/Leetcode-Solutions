// Last updated: 6/25/2026, 11:12:33 PM
class segTree{
private:

    struct Node{
        int pref, suff, best, len;
        char lc, rc;
    };

    int n;
    vector<Node> seg;

    string &s;

    Node merge(Node a, Node b){

        Node c;

        c.len = a.len + b.len;

        c.lc = a.lc;
        c.rc = b.rc;

        c.pref = a.pref;
        c.suff = b.suff;

        c.best = max(a.best, b.best);

        if(a.rc == b.lc){

            c.best = max(c.best, a.suff + b.pref);

            if(a.pref == a.len) c.pref = a.len + b.pref;

            if(b.suff == b.len) c.suff = b.len + a.suff;
        }

        return c;
    }

    void build(int idx, int l, int r){

        if(l == r){

            seg[idx] = {
                1, 1, 1, 1,
                s[l], s[l]
            };

            return;
        }

        int m = (l + r) / 2;

        build(idx * 2 + 1, l, m);
        build(idx * 2 + 2, m + 1, r);

        seg[idx] = merge(
            seg[idx * 2 + 1],
            seg[idx * 2 + 2]
        );
    }

    void update(int idx, int l, int r, int pos, char val){

        if(l == r){

            seg[idx] = {
                1, 1, 1, 1,
                val, val
            };

            return;
        }

        int m = (l + r) / 2;

        if(pos <= m)
            update(idx * 2 + 1, l, m, pos, val);
        else
            update(idx * 2 + 2, m + 1, r, pos, val);

        seg[idx] = merge(
            seg[idx * 2 + 1],
            seg[idx * 2 + 2]
        );
    }

public:

    segTree(string &s) : s(s){

        n = s.size();

        seg.resize(4 * n);

        build(0, 0, n - 1);
    }

    void update(int pos, char val){
        update(0, 0, n - 1, pos, val);
    }

    int query(){
        return seg[0].best;
    }
};

class Solution {
public:
    vector<int> longestRepeating(string s, string Q, vector<int>& QI) {

        segTree seg(s);

        vector<int> ans;

        for(auto [idx, ch] : views::zip(QI, Q)){

            seg.update(idx, ch);

            ans.push_back(seg.query());
        }

        return ans;
    }
};