// Last updated: 8/20/2026, 9:06:56 PM
class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        int ans = 0;

        for(int i = 0; i < n; i++){

            int freq[26] = {}; 
            int rem = 0;

            for(int j = i; j < n; j++){
                int idx = s[j] - 'a';

                if (freq[idx] == 0)  rem++;
                
                freq[idx]++;
                
                if (freq[idx] == k) rem--;

                if (!rem)  ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};