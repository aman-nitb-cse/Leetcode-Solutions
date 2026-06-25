// Last updated: 6/25/2026, 11:18:18 PM
class Solution {
public:
    bool solve(string &s, int i, int j){
        if(i == j) return s[i] == 't';
        if(s[i] == '!') return !solve(s, i + 2, j - 1);

        int prev = i + 2;
        int braces = 0;
        bool ans = (s[i] == '&');
        for(int k = i + 2; k <= j; k++){
            if(s[k] == '(') braces++;
            if(braces == 0 && (s[k] == ',' || s[k] == ')')){
                bool b = solve(s, prev, k - 1);
                ans = (s[i] == '&') ? ans && b : ans || b;
                prev = k + 1;
            }
            else if(s[k] == ')') braces--;
        }
        return ans;
    }
    bool parseBoolExpr(string s) {
        return solve(s, 0, s.size() - 1);
    }
};