// Last updated: 8/20/2026, 9:03:39 PM
class Solution {
public:
    vector<bool> used;
    int solve(int n){
        if(n == 0) return 1;
        int ans = 0;
        for(int i = 1; i < used.size(); i++){
            if(used[i]) continue;
            used[i] = true;
            if(i % n == 0 || n % i == 0) ans += solve(n - 1);
            used[i] = false;
        }
        return ans;
    }
    int countArrangement(int n) {
        used.assign(n + 1, false);
        return solve(n);
    }
};