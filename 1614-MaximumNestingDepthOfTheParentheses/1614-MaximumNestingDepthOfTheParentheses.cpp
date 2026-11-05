// Last updated: 11/6/2026, 5:00:50 AM
class Solution {
public:
    int maxDepth(string s) {
        int x = 0;

        int ans = -1;
        for(char &c : s){
            x += (c == '(') - (c == ')');
            ans = max(x, ans);
        }
        return ans;
    }
};