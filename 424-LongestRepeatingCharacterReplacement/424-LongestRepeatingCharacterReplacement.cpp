// Last updated: 8/20/2026, 9:06:07 PM
class Solution {
public:
    int characterReplacement(string w, int k) {
        int freq[26] = {0};
        int s = 0, e = -1, ans = 0;
        while(e < (int)w.size()){
            int req = (e - s + 1) - *ranges::max_element(freq);

            if(req > k){ // shrink
                freq[w[s++] - 'A']--;
            }
            else { // expand
                e++;
                ans = max(ans, e - s);
                if(e < w.size()) freq[w[e] - 'A']++;
            }
        }
        return ans;
    }
};