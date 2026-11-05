// Last updated: 11/6/2026, 5:01:55 AM
class Solution {
public:

    int numSub(string s) {
        long long count = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0') continue;
            int j;
            for(j = i; s[j] == '1' and j < s.size(); j++);
            long long n = j - i;
            if(n&1) count += n * ((n + 1) / 2);
            else count += (n / 2) * (n + 1);
            i = j;
        }
        return count % 1000000007;
    }
};