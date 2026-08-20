// Last updated: 8/20/2026, 8:44:29 PM
class Solution {
public:
    bool equalFrequency(string s) {
        int freq[26] = {};

        for(char &c : s) freq[c - 'a']++;


        for(char c = 'a'; c <= 'z'; c++){

            if(!freq[c-'a']) continue;

            freq[c - 'a']--;

            int f = 0;
            bool valid = true;

            for(int i = 0; i < 26; i++){
                if(freq[i]){
                    if(!f) f = freq[i];
                    else if(f != freq[i]){
                        valid = false;
                        break;
                    }
                }
            }

            freq[c - 'a']++;

            if(valid) return true;
        }

        return false;
    }
};