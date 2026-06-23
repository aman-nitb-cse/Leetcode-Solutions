// Last updated: 6/24/2026, 3:32:02 AM
class Solution {
public:
    bool checkStrings(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        vector<vector<int>> freq(2, vector<int>(26));
        for(int i = 0; i < s1.size(); i++){
            freq[i&1][s1[i] - 'a']++;
            freq[i&1][s2[i] - 'a']--;
        }

        for(auto &v : freq){
            for(int &i : v){
                if(i) return false;
            }
        }
        return true;
    }
};