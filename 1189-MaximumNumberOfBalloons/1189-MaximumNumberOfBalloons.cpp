// Last updated: 11/6/2026, 5:06:33 AM
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