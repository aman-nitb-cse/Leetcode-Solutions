// Last updated: 11/6/2026, 4:46:49 AM
class Solution {
public:
    int scoreOfString(string s) {
        int sum = 0;
        for(int i = 0; i < s.size() - 1; i++){
            sum += abs(s[i] - s[i + 1]);
        }
        return sum;
    }
};