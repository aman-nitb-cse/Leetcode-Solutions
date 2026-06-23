// Last updated: 6/24/2026, 3:28:35 AM
class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        
        unordered_map<string, int> hash;

        for(string &s : words){
            if(s.size() < k) continue;
            hash[s.substr(0, k)]++;
        }

        int count = 0;
        for(auto i = hash.begin(); i != hash.end(); i++){
            if(i->second > 1) count++;
        }
        return count;
    }
};