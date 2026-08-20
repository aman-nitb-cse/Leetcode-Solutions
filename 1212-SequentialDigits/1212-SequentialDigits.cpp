// Last updated: 8/20/2026, 8:55:19 PM
class Solution {
public:
    vector<int> ans;
    void f(int l, int r, int n){
        if(n <= r && n >= l) ans.push_back(n);
        if(n > r || n % 10 == 9) return;

        int d = n % 10 + 1;

        f(l, r, n * 10 + d);
    }
    vector<int> sequentialDigits(int l, int r) {
        

        for(int i = 1; i < 9; i++){
            f(l, r, i);
        }

        ranges::sort(ans);

        return ans;
    }
};