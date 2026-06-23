// Last updated: 6/24/2026, 3:29:00 AM
class Solution {
public:
    // int digitDP(string &s, int i){

    // }
    int totalWaviness(int num1, int num2) {
        // return digitDP(num2) - digitDP(num1 - 1);

        int cnt = 0;

        for(int i = num1; i <= num2; i++){
            string s = to_string(i);

            for(int j = 1; j + 2 <= s.size(); j++){
                cnt += s[j] > max(s[j - 1], s[j + 1]) || s[j] < min(s[j - 1], s[j + 1]);
            }
        }

        return cnt;
    }
};