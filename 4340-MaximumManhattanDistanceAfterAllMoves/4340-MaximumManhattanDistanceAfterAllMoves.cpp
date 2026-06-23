// Last updated: 6/24/2026, 3:26:28 AM
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