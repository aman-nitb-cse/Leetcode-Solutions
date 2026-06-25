// Last updated: 6/25/2026, 11:13:15 PM
class Solution {
public:
    string decodeCiphertext(string s, int r) {
        string ans = "";
        int n = s.size();
        int c = n / r;
        int i = 0, j = 0;
        while(true){
            int idx = i * c + j;
            if(idx >= n) break;
            ans += s[idx];

            i++;
            j++;
            if(i == r){
                i = 0;
                j -= r - 1;
            }
        }
        while(!ans.empty() && ans.back() == ' ') ans.pop_back();
        return ans;
    }
};