// Last updated: 6/25/2026, 11:12:22 PM
class Solution {
public:
    string digitSum(string s, int k) {
        if(s.size() <= k) return s;
        int sum = 0;
        string t = "";
        for(int i = 0; i < s.size(); i++){
            sum += s[i] - '0';
            if((i + 1) % k == 0){
                t += to_string(sum);
                sum = 0;
            }
        }

        if(s.size() % k) t += to_string(sum);
        return digitSum(t, k);
    }
};