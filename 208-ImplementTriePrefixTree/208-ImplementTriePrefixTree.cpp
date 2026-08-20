// Last updated: 8/20/2026, 9:11:44 PM
class Trie {
public:
    Trie* arr[26] = {nullptr};
    bool end = false;

    void insert(string s) {
        auto node = this;

        for(char &c : s){
            if(node->arr[c - 'a'] == nullptr) node->arr[c - 'a'] = new Trie();
            node = node->arr[c - 'a'];
        }

        node->end = true;
    }
    
    bool search(string s) {
        auto node = this;

        for(auto &c : s){
            if(node->arr[c - 'a'] == nullptr) return false;

            node = node->arr[c - 'a'];
        }
        return node->end;
    }
    
    bool startsWith(string s) {
        auto node = this;

        for(auto &c : s){
            if(node->arr[c - 'a'] == nullptr) return false;

            node = node->arr[c - 'a'];
        }
        return true;
    }
};