// Last updated: 11/6/2026, 4:31:14 AM
class SparseTable{
private:
    int n;
    vector<vector<int>> st;
public:
    SparseTable(vector<int>& arr){

        n = arr.size();

        if(n == 0) return;

        int max_log = log2(n) + 1;

        st.assign(n, vector<int> (max_log));

        for(int i = 0; i < n; i++){
            st[i][0] = arr[i];
        }

        for(int j = 1; j < max_log; j++){
            for(int i = 0; i + (1 << j) <= n; i++){
                st[i][j] = gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    int query(int ql, int qr){
        if(ql < 0 || qr >= n || ql > qr) return 0;
        int j = log2(qr - ql + 1);

        return gcd(st[ql][j], st[qr - (1 << j) + 1][j]);
    }
};

class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();

        SparseTable st(nums);

        int ans = 0;

        for(int k = -1; k < n; k++){
            int m = (k == -1) ? n : n - 1;

            if(m <= 1) continue;

            int tot = (k == -1) ? st.query(0, n - 1) : gcd(st.query(0, k - 1), st.query(k + 1, n - 1));

            auto pref = [&](int i){
                if(k == -1 || i < k) return st.query(0, i);
                return gcd(st.query(0, k - 1), st.query(k + 1, i + 1));
            };

            auto suf = [&](int i){
                if(k == -1) return st.query(i, n - 1);
                if(i < k) return gcd(st.query(i, k - 1), st.query(k + 1, n - 1));
                return st.query(i + 1, n - 1);
            };

            int left = m, s = 0, e = m - 2; 
            while(s <= e){
                int mid = s + (e - s) / 2;
                if(pref(mid) == tot){
                    left = mid;
                    e = mid - 1;
                }
                else s = mid+ 1;
            }

            int right = -1;
            s = 0, e = m - 2;
            while(s <= e){
                int mid = s + (e - s) / 2;
                if(suf(mid + 1) == tot){
                    right = mid;
                    s = mid + 1;
                    // cout << right << endl;
                }
                else e = mid - 1;
            }

            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};





















