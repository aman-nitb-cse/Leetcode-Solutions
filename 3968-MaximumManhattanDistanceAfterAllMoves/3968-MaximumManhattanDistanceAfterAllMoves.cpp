// Last updated: 11/6/2026, 4:32:10 AM
class Solution {
public:
    int maxDistance(string moves) {
        int x = 0, y = 0, _ = 0;

        for(char &c : moves){
            if(c == 'U') y++;
            else if(c == 'D') y--;
            else if(c == 'L') x--;
            else if(c == 'R') x++;
            else _++;
        }

        x = abs(x);
        y = abs(y);

        return x + y + _;
    }
};