// Last updated: 11/6/2026, 5:08:35 AM
class Solution {
public:
    bool canBeFormed(string word, string chars){
        unordered_map <char, int> hash;
        for(char &c : chars) hash[c]++;
        for(char &c : word){
            if(hash.find(c) == hash.end()) return false;
            hash[c]--;
            if(hash[c] < 0) return false;
        }
        return true;
    }

    int countCharacters(vector<string>& words, string chars) {
        int ans = 0;
        for(string &s : words){
            ans += s.size() * canBeFormed(s, chars);
        }
        return ans;
    }
};