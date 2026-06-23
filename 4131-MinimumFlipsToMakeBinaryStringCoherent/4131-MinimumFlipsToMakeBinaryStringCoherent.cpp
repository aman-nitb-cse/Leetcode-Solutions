// Last updated: 6/24/2026, 3:28:38 AM
class Solution {
public:
    int minFlips(string s) {
        int right_zeros = ranges::count(s, '0');
        int right_ones = s.size() - right_zeros;
        int left_zeros = 0, left_ones = 0, cnt = 0;
        
        for(char &c : s){
            if(c == '0') {
                right_zeros--;
                left_zeros++;
            }
            else {
                right_ones--;

                if(left_ones && right_zeros || right_ones && left_zeros) {
                    cnt++;
                    left_zeros++;
                }
                else left_ones++;
            }
        }

        return min(cnt, (int)ranges::count(s, '0'));
    }
};

// string contain single 1 || all ones