// Last updated: 8/20/2026, 9:18:25 PM
class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        vector<int> v(n);

        int maxi = 0;
        for(int i = 0; i < n; i++){
            maxi = max(maxi, h[i]);
            v[i] = maxi;
        }

        maxi = 0;
        for(int i = n - 1; i >= 0; i--){
            maxi = max(maxi, h[i]);
            v[i] = min(maxi, v[i]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += v[i] - h[i];
        }
        return ans;
    }
};