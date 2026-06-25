// Last updated: 6/25/2026, 11:16:28 PM
class Solution {
public:

    using ull = unsigned long long;

    string longestPrefix(string s) {

        const ull base = 131;

        ull pre = 0;
        ull suf = 0;
        ull pw = 1;

        int len = 0;

        for(int i = 0, j = s.size() - 1; j > 0; i++, j--){

            pre = pre * base + s[i];

            suf = s[j] * pw + suf;

            pw *= base;

            if(pre == suf) len = i + 1;
        }

        return s.substr(0, len);
    }
};