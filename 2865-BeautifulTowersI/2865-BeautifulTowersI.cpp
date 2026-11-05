// Last updated: 11/6/2026, 4:49:17 AM
class Solution {
public:
    using ll = long long;

    long long maximumSumOfHeights(vector<int>& a) {
        ll ans = 0;

        for(int i = 0; i < a.size(); i++){
            ll sum = a[i];

            int h = a[i];
            for(int j = i - 1; j >= 0; j--){
                h = min(h, a[j]);
                sum += h;
            }

            h = a[i];
            for(int j = i + 1; j < a.size(); j++){
                h = min(h, a[j]);
                sum += h;
            }

            ans = max(ans, sum);
        }

        return ans;
    }
};