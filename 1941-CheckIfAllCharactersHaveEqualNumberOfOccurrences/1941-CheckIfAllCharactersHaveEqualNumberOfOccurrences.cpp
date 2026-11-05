// Last updated: 11/6/2026, 4:57:00 AM
class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int freq[26] = {0};

        for(char &c : s) freq[c - 'a']++;

        return ranges::all_of(freq, 
            [&](auto &i){
                return i == 0 || i == freq[s[0] - 'a'];
            }
        );
    }
};