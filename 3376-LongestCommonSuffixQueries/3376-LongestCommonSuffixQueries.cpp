// Last updated: 6/24/2026, 3:31:03 AM
class Trie {
public:
    Trie* c[26] = {};
    int index = -1;
    ~Trie() { //Adding a desctructor
        for (int i = 0; i < 26; i++) delete c[i];
    }
    
    // insert word
    void insert(vector<string>& w, int idx) {
        auto node = this;
        
        if(node->index == -1 || w[node->index].size() > w[idx].size()) node->index = idx;

        for(char ch : w[idx] | views::reverse){
            int i = ch - 'a';
            if(!node->c[i]) node->c[i] = new Trie();
            node = node->c[i];
            if(node->index == -1 || w[node->index].size() > w[idx].size()) node->index = idx;
        }
    }
    
    // count prefix occurrences
    int suffix(string &s) {
        auto node = this;
        for(char ch : s | views::reverse){
            int i = ch - 'a';
            if(!node->c[i]) return node->index;
            node = node->c[i];
        }
        return node->index;
    }
};
class Solution {
public:
    vector<int> stringIndices(vector<string>& w, vector<string>& q) {
        Trie* tr = new Trie();
        for(int i = 0; i < w.size(); i++) tr->insert(w, i);

        vector<int> ans;
        for(auto &s : q){
            ans.push_back(tr->suffix(s));
        }
        delete tr;
        return ans;
    }
};