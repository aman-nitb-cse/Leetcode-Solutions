// Last updated: 11/6/2026, 4:57:46 AM
class Solution {
public:
    bool checkZeroOnes(string s) {
        int i = 0, j = 0;
        unordered_map <char, int> hash = {{'1', 0}, {'0', 0}};
        while(j < s.size()){
            if(s[j] == s[i]) j++;
            else {
                hash[s[i]] = max(hash[s[i]], j - i);
                i = j;
            }
        }
        hash[s[i]] = max(hash[s[i]], j - i);
        return hash['1'] > hash['0'];
    }
};