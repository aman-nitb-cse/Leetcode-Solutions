// Last updated: 8/20/2026, 9:05:07 PM
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for(int i = 1; i <= n; i++){ // i : window size
            if(n % i) continue;
            for(int j = i; j <= n - i; j += i){
                if(s.substr(0, i) != s.substr(j, i)) break;
                if(j == n - i) return true;
            }
        }
        return false;
    } 
};