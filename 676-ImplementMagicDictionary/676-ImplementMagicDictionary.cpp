// Last updated: 6/25/2026, 11:37:26 PM
class Trie {
public:
    Trie* c[26] = {};
    int end = 0;

    Trie(vector<string> &w){
        for(string &s : w){
            insert(s);
        }
    }

    Trie(){}
    
    // insert word
    void insert(string &s) {
        auto node = this;
        for(char ch : s){
            int i = ch - 'a';
            if(!node->c[i]) node->c[i] = new Trie();
            node = node->c[i];
        }
        node->end++;
    }
    
    // count exact occurrences
    bool search(string &s, int i = 0, bool canChange = true) {
        if(i == s.size()) return !canChange && end;

        // change
        for(int idx = 0; idx < 26; idx++){
            if((canChange || idx == s[i] - 'a') && c[idx] && c[idx]->search(s, i + 1, canChange && (idx == s[i] - 'a'))) return true;
        }

        return false;
    }

    // Adding a desctructor
    ~Trie() { 
        for (int i = 0; i < 26; i++) delete c[i];
    }
};

class MagicDictionary {
public:
    Trie* root = NULL;
    void buildDict(vector<string> d) {
        delete root;
        root = new Trie(d);
    }
    
    bool search(string s) {
        return root->search(s);
    }
};