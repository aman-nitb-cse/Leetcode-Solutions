// Last updated: 6/25/2026, 11:37:32 PM
class Solution {
public:
    void solve(vector<int>& v, int i = 0){
        if(i == v.size()) return;
        auto mx = max_element(v.rbegin(), v.rend() - i);
        if(v[i] == *mx) solve(v, i + 1); // first element is max
        else swap(*mx, v[i]);
    }
    int maximumSwap(int n) {
        vector<int> v;
        while(n){
            v.push_back(n % 10);
            n /= 10;
        }
        reverse(v.begin(), v.end());
        solve(v);
        n = 0;
        for(int &i : v){
            n = 10 * n + i;
        }
        return n;
    }
};