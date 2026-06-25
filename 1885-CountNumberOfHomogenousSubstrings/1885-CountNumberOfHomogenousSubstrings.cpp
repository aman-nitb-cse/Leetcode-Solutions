// Last updated: 6/25/2026, 11:14:55 PM
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