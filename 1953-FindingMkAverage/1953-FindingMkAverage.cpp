// Last updated: 6/25/2026, 11:14:41 PM
class segTree {
public:
    int n;

    vector<int> cnt;
    vector<long long> sum;

    segTree(int n) : n(n) {
        cnt.resize(4 * n);
        sum.resize(4 * n);
    }

    void update(int idx, int l, int r, int pos, int delta) {

        if(l == r) {
            cnt[idx] += delta;
            sum[idx] += 1LL * delta * (l + 1);
            return;
        }

        int m = (l + r) / 2;

        if(pos <= m) update(idx * 2 + 1, l, m, pos, delta);
        else update(idx * 2 + 2, m + 1, r, pos, delta);

        cnt[idx] = cnt[idx * 2 + 1] + cnt[idx * 2 + 2];

        sum[idx] = sum[idx * 2 + 1] + sum[idx * 2 + 2];
    }

    long long firstK(int idx, int l, int r, int k) {

        if(k == 0) return 0;

        if(l == r)
            return 1LL * k * (l + 1);

        int m = (l + r) / 2;

        if(cnt[idx * 2 + 1] >= k)
            return firstK(
                idx * 2 + 1,
                l,
                m,
                k
            );

        return sum[idx * 2 + 1] +
               firstK(
                   idx * 2 + 2,
                   m + 1,
                   r,
                   k - cnt[idx * 2 + 1]
               );
    }

    long long firstK(int k){
        return firstK(0, 0, 99999, k);
    }

    long long totalSum() {
        return sum[0];
    }
};

class MKAverage {
public:

    int m, k;

    queue<int> q;

    segTree st;

    MKAverage(int m, int k) : m(m), k(k), st(100000) {}

    void addElement(int num) {

        q.push(num);

        st.update(0, 0, 99999, num - 1, 1);

        if(q.size() > m){

            int x = q.front();
            q.pop();

            st.update(0, 0, 99999, x - 1, -1);
        }
    }

    int calculateMKAverage() {

        if(q.size() < m) return -1;

        return (st.firstK(m - k) - st.firstK(k)) / (m - 2 * k);
    }
};