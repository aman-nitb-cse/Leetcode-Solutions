// Last updated: 8/20/2026, 8:26:54 PM
class Solution {
public:
    int countValidPrefixes(string s) {
        int cnt = 0;

        int freq[2] = {};

        for(char &c : s){
            freq[c - '0']++;

            if(abs(freq[0] - freq[1]) <= 1) cnt++;
        }

        return cnt;
    }
};