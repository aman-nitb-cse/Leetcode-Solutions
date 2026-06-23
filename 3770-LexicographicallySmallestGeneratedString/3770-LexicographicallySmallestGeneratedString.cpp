// Last updated: 6/24/2026, 3:29:58 AM
class Solution {
public:
    string generateString(string a, string b) {
        int m = a.size(), n = b.size();
        string s;

        for(int i = 0; i < m; i++){
            if(a[i] == 'T') s = s.substr(0, i) + b;
            else {
                int x = s.size();
                s += string(i + n - x, '#');
            }
        }

        // check for all T and F
        for(int i = 0; i < m; i++){
            if(b == s.substr(i, n)){
                if(a[i] == 'F') return "";
            }
            else if(a[i] == 'T') return "";
        }
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] != '#') continue;

            for(char c = 'a'; c <= 'z'; c++){
                s[i] = c;
                bool valid = true;
                for(int j = max(0, i - n + 1); j <= i; j++){
                    if(j < m && a[j] == 'F' && s.substr(j, n) == b){
                        valid = false;
                        break;
                    }
                }
                if(valid) break;
            }
        }
        return s;
    }
};