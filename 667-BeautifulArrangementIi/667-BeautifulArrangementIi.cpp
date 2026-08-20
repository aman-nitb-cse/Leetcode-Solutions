// Last updated: 8/20/2026, 9:01:14 PM
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans(n);

        int x = 1;
        int y = n;

        for(int i = 0; i < n; i++){
            if(i & 1) ans[i] = y--;
            else ans[i] = x++;
        }

        ranges::sort(ans | views::drop(k));
        if((k & 1) == 0) ranges::reverse(ans | views::drop(k));
        return ans;
    }
};