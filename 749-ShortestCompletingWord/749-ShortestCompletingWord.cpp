// Last updated: 6/25/2026, 11:21:38 PM
class Solution {
public:
    string shortestCompletingWord(string s, vector<string>& w) {
        int freq[26] = {0};
        for(char &c : s) {
            c = tolower(c);
            if(c >= 'a' && c <= 'z') freq[c - 'a']++;
        }

        string ans = "";
        for(string &x : w){
            int _freq[26] = {0};
            for(char &c : x) {
                c = tolower(c);
                if(c >= 'a' && c <= 'z') _freq[c - 'a']++;
            }
                

            bool valid = true;
            for(char &c : s){
                c = tolower(c);
                if((c >= 'a' && c <= 'z') && _freq[c - 'a'] < freq[c - 'a']){
                    valid = false;
                    break;
                }
            }

            if(valid && (ans == "" || ans.size() > x.size())) ans = x;
        }
        return ans;
    }
};