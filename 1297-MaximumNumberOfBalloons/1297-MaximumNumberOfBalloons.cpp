// Last updated: 6/25/2026, 11:17:49 PM
class Solution {
public:
    int maxNumberOfBalloons(string s) {
        int mini = s.size();

        for(char c : string("balon")){
            int x = ranges::count(s, c);

            if(c == 'l' || c == 'o') x >>= 1;

            mini = min(mini, x);
        }

        return mini;
    }
};