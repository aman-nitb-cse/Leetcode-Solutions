// Last updated: 8/20/2026, 9:12:22 PM
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> freq; 

        for(int i = 0; i + 9 < s.size(); i++){
            freq[s.substr(i, 10)]++;
        }

        vector<string> ans;
        for(auto &[str, f] : freq){
            if(f > 1) ans.push_back(str);
        }
        return ans;
    }
};