// Last updated: 6/25/2026, 11:13:03 PM
class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if(n & 1) return false;

        int opens = 0, free = 0;

        // left to right
        for(int i = 0; i < n; i++){
            if(locked[i] == '0') free++;
            else if(s[i] == '(') opens++;
            else if(opens > 0) opens--;
            else if(free > 0) free--;
            else return false;
        }

        int closes = 0; free = 0;

        // right to left
        for(int i = n - 1; i >= 0; i--){
            if(locked[i] == '0') free++;
            else if(s[i] == ')') closes++;
            else if(closes > 0) closes--;
            else if(free > 0) free--;
            else return false;
        }

        return true;
    }
};