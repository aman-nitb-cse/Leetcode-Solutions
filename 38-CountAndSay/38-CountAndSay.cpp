// Last updated: 8/20/2026, 9:18:34 PM
class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string s = countAndSay(n - 1);

        string ans = "";
        char prev = s.back();
        s.pop_back();
        int count = 1;

        while(!s.empty()){
            if(prev == s.back()){
                s.pop_back();
                count++;
            }
            else {
                ans.push_back(prev);
                ans.push_back(count + '0');
                prev = s.back();
                s.pop_back();
                count = 1;
            }
        }

        if(count){
            ans.push_back(prev);
            ans.push_back(count + '0');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};