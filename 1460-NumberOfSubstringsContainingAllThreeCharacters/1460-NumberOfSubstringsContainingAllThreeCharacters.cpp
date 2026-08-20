// Last updated: 8/20/2026, 8:53:06 PM
class Solution {
public:
    int numberOfSubstrings(string s) {
        // count opposite

        int l = 0, r = -1;
        long long cnt = 0, n = s.size();
        int freq[3] = {};

        while(r < n){
            if(freq[0] && freq[1] && freq[2]){ // shrink
                freq[s[l++] - 'a']--;
            }
            else { // expand
                cnt += r - l + 1;
                r++;
                if(r < n) freq[s[r] - 'a']++;
            }
        }

        return n * (n + 1) / 2  - cnt;
    }
};