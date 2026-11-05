// Last updated: 11/6/2026, 5:00:14 AM
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