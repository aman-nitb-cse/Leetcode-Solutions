// Last updated: 6/25/2026, 11:11:42 PM
class Trie {
public:
    Trie* c[26] = {};
    int pref = 0, end = 0;
    
    // insert word
    void insert(string &s) {
        auto node = this;
        for(char ch : s){
            int i = ch - 'a';
            if(!node->c[i]) node->c[i] = new Trie();
            node = node->c[i];
            node->pref++;
        }
        node->end++;
    }
    
    // count prefix occurrences
    int count(string &s) {
        int ans = 0;
        auto node = this;
        for(char ch : s){
            int i = ch - 'a';
            if(!node->c[i]) return 0;
            node = node->c[i];
            ans += node->pref;
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& w) {
        Trie* trie = new Trie();
        for(auto &s : w) trie->insert(s);

        vector<int> ans(w.size());
        for(int i = 0; i < w.size(); i++){
            ans[i] += trie->count(w[i]);
        }
        return ans;
    }
};