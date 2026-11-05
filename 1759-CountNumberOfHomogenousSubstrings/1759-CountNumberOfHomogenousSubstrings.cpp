// Last updated: 11/6/2026, 4:59:15 AM
class Solution {
public:
    int countHomogenous(string s) {
        long long count = 0;
        int i = 0, j = 0;
        while(j < s.size()){
            if(s[j] == s[i]) j++;
            else {
                long long n = j - i;
                count += n * (n + 1) / 2;
                i = j;
            }
        }
        long long n = j - i;
        count += n * (n + 1) / 2;
        return count % 1000000007;
    }
};