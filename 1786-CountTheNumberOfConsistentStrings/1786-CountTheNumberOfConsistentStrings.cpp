// Last updated: 6/25/2026, 11:15:19 PM
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map <char, int> hash;
        for(char &c : allowed) hash[c]++;
        
        int count = 0;
        for(string &s : words){
            bool isConsistent = true;
            for(char &c : s){
                if(hash.find(c) == hash.end()) isConsistent = false;
            }
            if(isConsistent) count++;
        }
        return count;
    }
};