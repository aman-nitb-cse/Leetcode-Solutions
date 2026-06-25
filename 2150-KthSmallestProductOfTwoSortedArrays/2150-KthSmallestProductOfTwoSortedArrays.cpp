// Last updated: 6/25/2026, 11:13:32 PM
class Solution {
public:
    long long kthSmallestProduct(vector<int>& a, vector<int>& b, long long k) {
        int m = a.size(), n = b.size();
        if(m > n) return kthSmallestProduct(b, a, k);

        long long s = min({
            1LL * a[0] * b[0],
            1LL * a[0] * b[n - 1],
            1LL * a[m - 1] * b[0],
            1LL * a[m - 1] * b[n - 1]
        });

        long long e = max({
            1LL * a[0] * b[0],
            1LL * a[0] * b[n - 1],
            1LL * a[m - 1] * b[0],
            1LL * a[m - 1] * b[n - 1]
        });

        while(s < e){
            long long mid = s + (e - s) / 2;
            long long count = 0;
            for(int &x : a){
                if(x == 0){
                    if(mid >= 0) count += n;
                }
                else if(x > 0){ // inc
                    // binary search

                    int i = 0, j = n - 1;
                    while(i <= j){
                        int m = i + (j - i) / 2;

                        if(1LL * b[m] * x <= mid) i = m + 1;
                        else j = m - 1;
                    }
                    count += i;
                }
                else { // dec
                    int i = 0, j = n - 1;
                    while(i <= j){
                        int m = i + (j - i) / 2;

                        if(1LL * b[m] * x > mid) i = m + 1;
                        else j = m - 1;
                    }
                    count += n - i;
                }
            }

            if(count < k) s = mid + 1;
            else e = mid;
        }
        return s;
    }
};