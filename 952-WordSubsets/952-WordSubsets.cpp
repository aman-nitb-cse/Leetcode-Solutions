// Last updated: 6/25/2026, 11:19:51 PM
class Solution {
public:
    vector<string> wordSubsets(vector<string>& w1, vector<string>& w2) {
        int freq[26] = {0};

        for(string &s : w2){
            int _freq[26] = {0};
            for(char &c : s) _freq[c - 'a']++;

            for(int i = 0; i < 26; i++){
                freq[i] = max(freq[i], _freq[i]);
            }
        }

        w2.clear();
        for(string &s : w1){
            int _freq[26] = {0};
            for(char &c : s) _freq[c - 'a']++;

            bool valid = true;
            for(int i = 0; i < 26; i++){
                if(_freq[i] < freq[i]){
                    valid = false;
                    break;
                }
            }
            if(valid) w2.push_back(s);
        }
        return w2;
    }
};