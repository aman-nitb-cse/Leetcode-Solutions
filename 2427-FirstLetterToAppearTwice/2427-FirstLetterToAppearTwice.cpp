// Last updated: 6/25/2026, 11:12:05 PM
class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map <char, int> hash;
        for(char &c : s){
            if(hash.find(c) != hash.end() and hash[c] == 1) return c;
            hash[c]++;
        }
        return -1;
    }
};