// Last updated: 11/6/2026, 4:48:29 AM
class Solution {
public:
    int removeAlmostEqualCharacters(string s) {
        int ans = 0;

        for(int i = 1; i < s.size(); i++){
            if(abs(s[i] - s[i - 1]) <= 1){
                ans++;
                i++;
            }
        }

        return ans;
    }
};