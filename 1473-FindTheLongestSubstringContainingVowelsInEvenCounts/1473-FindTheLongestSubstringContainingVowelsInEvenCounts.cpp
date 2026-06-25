// Last updated: 6/25/2026, 11:16:41 PM
class Solution {
public:
    unordered_map<char,int> idx = {
        {'a', 0},
        {'e', 1},
        {'i', 2},
        {'o', 3},
        {'u', 4}
    };
    using bit = bitset<5>;
    int findTheLongestSubstring(string s) {
        
        int ans = 0;
        bit b;

        unordered_map<bit,int> prev = {{b, -1}};

        for(int i = 0; i < s.size(); i++){

            if(idx.count(s[i])) b.flip(idx[s[i]]);

            if(prev.count(b)) ans = max(ans, i - prev[b]);
            else prev[b] = i;
        }
        return ans;
    }
};