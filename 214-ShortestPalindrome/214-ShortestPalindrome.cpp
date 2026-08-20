// Last updated: 8/20/2026, 9:11:26 PM
class Solution {
public:

    using ull = unsigned long long;

    string shortestPalindrome(string s) {

        const ull base = 131;

        ull pre = 0;
        ull suf = 0;
        ull pw = 1;

        int idx = -1;

        for(int i = 0; i < s.size(); i++){

            pre = pre * base + s[i];

            suf = suf + pw * s[i];

            pw *= base;

            if(pre == suf) idx = i;
        }

        string add = s.substr(idx + 1);

        ranges::reverse(add);

        return add + s;
    }
};