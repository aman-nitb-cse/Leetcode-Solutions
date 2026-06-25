// Last updated: 6/25/2026, 11:16:04 PM
class Solution {
public:
    bool isVowel(char &c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxVowels(string s, int k) {
        int ans = 0;
        int curr = 0;

        for(int i = 0; i < k; i++) curr += isVowel(s[i]);

        for(int i = 0; i < s.size() - k + 1; i++){
            ans = max(ans, curr);

            // for next
            curr -= isVowel(s[i]);
            if(i + k < s.size()) curr += isVowel(s[i + k]);
        }
        return ans;
    }
};