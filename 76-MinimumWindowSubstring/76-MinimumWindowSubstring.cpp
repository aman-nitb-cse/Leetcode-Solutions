// Last updated: 8/20/2026, 9:16:42 PM
class Solution {
public:
    string minWindow(string s, string t) {
        int freq[58] = {0}, curr[58] = {0};
        int m = s.size(), n = t.size();

        for(char &i : t) freq[i - 'A']++;

        int count = 0, i = 0, j = -1;
        int start = 0, size = 0;
        while(j < m){

            if(count == n && (size == 0 || size > j - i + 1)){
                start = i;
                size = j - i + 1;
            } 

            if(count < n){
                // expand
                j++;
                if(j < m){
                    curr[s[j] - 'A']++;
                    if(curr[s[j] - 'A'] <= freq[s[j] - 'A']) count++;
                }
            }
            else {
                // shrink
                curr[s[i] - 'A']--;
                if(curr[s[i] - 'A'] < freq[s[i] - 'A']) count--;
                i++;
            }
        }
        return s.substr(start, size);
    }
};