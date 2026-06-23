// Last updated: 6/24/2026, 3:27:15 AM
class Solution {
public:
    char mirror(char c){
        if(c <= 'z' && c >= 'a') return 'a' + ('z' - c);
        return '0' + '9' - c;
    }
    int mirrorFrequency(string s) {
        vector<int> freq(128, 0);

        for(char &c : s) freq[c]++;

        int ans = 0;
        for(char i = 'a'; i <= 'm'; i++) ans += abs(freq[i] - freq[mirror(i)]);
        for(char i = '0'; i <= '4'; i++) ans += abs(freq[i] - freq[mirror(i)]);

        return ans;
    }
};