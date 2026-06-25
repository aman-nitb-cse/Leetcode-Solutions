// Last updated: 6/25/2026, 11:17:24 PM
class Trie {
public:
    Trie* arr[26] = {nullptr};
    bool end = false;
    vector<string> dict;

    void insert(string &s, int i = 0) {
        dict.push_back(s);
        sort(dict.begin(), dict.end());
        if(dict.size() > 3) dict.pop_back();
        if(i == s.size()){
            end = true;
            return;
        }
        if(!arr[s[i] - 'a']) arr[s[i] - 'a'] = new Trie();
        arr[s[i] - 'a']->insert(s, i + 1);
    }
    
    void solve(vector<vector<string>> &ans, string &w) {
        auto node = this;

        for(auto &c : w){
            if(node->arr[c - 'a'] == nullptr) return;
            node = node->arr[c - 'a'];
            ans.push_back(node->dict);
        }
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& d, string s) {
        auto node = new Trie();
        for(string &w : d){
            node->insert(w);
        }
        vector<vector<string>> ans;
        node->solve(ans, s);
        ans.resize(s.size());
        return ans;
    }
};