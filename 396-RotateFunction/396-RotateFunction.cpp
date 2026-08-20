// Last updated: 8/20/2026, 9:06:52 PM
class Solution {
public:
    int maxRotateFunction(vector<int>& v) {
        int n = v.size();
        int sum = 0, f = 0;
        
        for(int i = 0; i < n; i++){
            sum += v[i];
            f += i * v[i];
        }
        
        int ans = f;
        
        for(int k = 1; k < n; k++){
            f = f + sum - 1LL * n * v[n - k];
            ans = max(ans, f);
        }
        
        return ans;
    }
};