// Last updated: 6/24/2026, 3:29:41 AM
class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> hash;

        for(char &c : s) hash[c]++;

        int v = 0, c = 0;

        for(auto i = hash.begin(); i != hash.end(); i++){
            if(i->first == 'a' || i->first == 'e' || i->first == 'i' || i->first == 'o' || i->first == 'u'){
                v = max(v, i->second);
            }
            else c = max(c, i->second);
        }
        return v + c;
    }
};