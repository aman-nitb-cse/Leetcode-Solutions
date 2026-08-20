// Last updated: 8/20/2026, 9:19:03 PM
class Solution {
public:
    vector<int> freq, match;
    unordered_map<string, int> id;
    int m, n;

    bool check(int i, int cnt){
        if(cnt == n) return true;

        int x = match[i];

        if(x == -1 || freq[x] == 0) return false;

        freq[x]--;
        bool ans = check(i + m, cnt + 1);
        freq[x]++;

        return ans;
    }

    vector<int> findSubstring(string s, vector<string>& w) {
        m = w[0].size();
        n = w.size();

        int idx = 0;

        for(auto &x : w){
            if(!id.count(x))
                id[x] = idx++;
        }

        freq.assign(idx, 0);

        for(auto &x : w) freq[id[x]]++;

        match.assign(s.size(), -1);

        for(int i = 0; i + m <= s.size(); i++){
            auto it = id.find(s.substr(i, m));
            if(it != id.end())
                match[i] = it->second;
        }

        vector<int> ans;
        int k = m * n;

        for(int i = 0; i + k <= s.size(); i++){
            if(check(i, 0))
                ans.push_back(i);
        }

        return ans;
    }
};