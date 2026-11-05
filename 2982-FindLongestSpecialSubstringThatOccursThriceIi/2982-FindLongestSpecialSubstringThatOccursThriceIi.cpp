// Last updated: 11/6/2026, 4:48:00 AM
class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();

        vector<vector<int>> cnt(26, vector<int> (n + 1));

        char curr = 'a';
        int streak = 0;

        auto calc = [&](){
            for(int i = 0; i <= 2 && streak >= i; i++){
                cnt[curr - 'a'][streak - i] += i + 1;
            }
        };

        for(char &c : s){
            if(c == curr) streak++;
            else {
                calc();
                curr = c;
                streak = 1;
            }
        }

        calc();

        for(int i = n - 2; i; i--){
            for(int j = 0; j < 26; j++){
                if(cnt[j][i] >= 3) return i;
            }
        }

        return -1;
    }
};