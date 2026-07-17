// Last updated: 7/18/2026, 12:22:00 AM
class Solution {
public:
    using ull = unsigned long long;
    const ull base = 131;

    long long getSum(vector<int>& nums) {
        int n = nums.size();

        vector<ull> pref(n), suf(n), pw(n + 1), sum(n);

        pw[0] = 1;
        for(int i = 1; i <= n; i++) pw[i] = pw[i - 1] * base;

        pref[0] = nums[0];
        for(int i = 1; i < n; i++) pref[i] = pref[i - 1] * base + nums[i];

        suf[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--) suf[i] = suf[i + 1] * base + nums[i];

        auto forward = [&](int l, int r){
            ull h = pref[r];
            if(l) h -= pref[l - 1] * pw[r - l + 1];
            return h;
        };

        for(int i = 0; i < n; i++){
            sum[i] = nums[i];
            if(i) sum[i] += sum[i - 1];
        }

        auto backward = [&](int l, int r){
            ull h = suf[l];
            if(r + 1 < n) h -= suf[r + 1] * pw[r - l + 1];
            return h;
        };

        auto check = [&](int l, int r) {
            return forward(l, r) == backward(l, r);
        };

        auto getSum = [&](int l, int r){
            return sum[r] - (l ? sum[l - 1] : 0);
        };

        ull ans = 0;
        for(int i = 0; i < n; i++){
            int s = 0, e = min(i, n - i - 1);

            while(s < e){
                int mid = (s + e + 1) / 2;
                if(check(i - mid, i + mid)){
                    s = mid;
                }
                else e = mid - 1;
            }

            ans = max(ans, getSum(i - s, i + s));
        }

        for(int i = 1; i < n; i++){
            int s = -1, e = min(i - 1, n - i - 1);

            while(s < e){
                int mid = (s + e + 1) / 2;

                if(check(i - mid - 1, i + mid)){
                    s = mid;
                }
                else{
                    e = mid - 1;
                }
            }

            if(s != -1){
                ans = max(ans, getSum(i - s - 1, i + s));
            }
        }

        return ans;
    }
};