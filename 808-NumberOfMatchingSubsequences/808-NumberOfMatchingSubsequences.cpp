// Last updated: 6/25/2026, 11:21:08 PM
class Solution {
public:
    vector<vector<int>> pos;
    bool isSubsequence(string s, string t) {
        int prev = -1;
        for(char &i : t){
            auto it = ranges::upper_bound(pos[i - 'a'], prev);
            if(it == pos[i - 'a'].end()) return false;
            prev = *it;
        }
        return true;
    }

    int numMatchingSubseq(string s, vector<string>& words) {

        pos.assign(26, {});
        for(int i = 0; i < s.size(); i++){
            pos[s[i] - 'a'].push_back(i);
        }

        int count = 0;
        unordered_map <string, bool> mp;
        for(string &str : words){
            if(mp.count(str) == 0) mp[str] = isSubsequence(s, str);
            count += mp[str];
        }
        return count; 
    }
};