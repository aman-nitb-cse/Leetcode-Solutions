// Last updated: 11/6/2026, 4:32:47 AM
class Solution {
public:
    int passwordStrength(string s) {
        int ans = 0;
        for(char c = 'a'; c <= 'z'; c++){
            if(s.find(c) != string::npos) ans += 1;
            if(s.find(c - 'a' + 'A') != string::npos) ans += 2;
        }

        for(char c = '0'; c <= '9'; c++){
            if(s.find(c) != string::npos) ans += 3;
        }

        for(char c : "!@#$"){
            if(s.find(c) != string::npos) ans += 5;
        }

        return ans;
    }
};