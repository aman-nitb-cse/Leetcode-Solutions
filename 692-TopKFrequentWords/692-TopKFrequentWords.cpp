// Last updated: 6/25/2026, 11:37:12 PM
class Solution {
public:
    vector<string> topKFrequent(vector<string>& w, int k) {
        unordered_map<string, int> freq;
        for(string &s : w) freq[s]++;

        vector<pair<int,string>> v;

        for(auto& [s, f] : freq) v.push_back({f, s});

        ranges::sort(v,
            [](auto &a, auto &b){
                if(a.first != b.first) return a.first > b.first;
                return a.second < b.second;
            }
        );

        w.clear();
        for(auto &[f, s] : v){
            w.push_back(s);
            if(w.size() == k) break;
        }
        return w;
    }
};