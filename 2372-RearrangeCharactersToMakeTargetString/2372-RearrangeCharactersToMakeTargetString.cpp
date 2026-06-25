// Last updated: 6/25/2026, 11:12:18 PM
class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map <char, int> Hash;
        for(char &c : s) Hash[c]++;

        unordered_map <char, int> targetHash;
        for(char &c : target) targetHash[c]++;

        int mini = s.size() / target.size();
        for(char &c : target){
            if(Hash.find(c) == Hash.end()) return 0;
            mini = min(mini, Hash[c] / targetHash[c]);
        }
        return mini;
    }
};