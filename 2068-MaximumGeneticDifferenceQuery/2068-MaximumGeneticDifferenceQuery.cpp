// Last updated: 6/25/2026, 11:13:58 PM
class trie {
public:
    trie* bits[2] = {NULL, NULL};
    int count = 0;
    
    void insert(int x) {
        trie* node = this;
        for (int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1;
            if (!node->bits[bit]) node->bits[bit] = new trie();
            node = node->bits[bit];
            node->count++;
        }
    }
    
    void erase(int x) {
        trie* node = this;
        for (int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1;
            trie* nxt = node->bits[bit];
            if (!nxt) return;
            
            nxt->count--;
            
            if (nxt->count == 0) {
                node->bits[bit] = NULL;
                return;
            }
            node = nxt;
        }
    }
    
    int maxXorWith(int x) {
        trie* node = this;
        int ans = 0;
        
        for (int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1;
            int want = bit ^ 1;
            
            if (node->bits[want]) {
                ans |= (1 << i);
                node = node->bits[want];
            } else if (node->bits[bit]) {
                node = node->bits[bit];
            } else {
                break; // trie is empty or malformed
            }
        }
        return ans;
    }
    
    int maxXor(trie* a, trie* b, int bit = 31) {
        if (!a || !b || bit < 0) return 0;
        
        int best = 0;
        
        if (a->bits[0] && b->bits[1])
            best = max(best, (1 << bit) | maxXor(a->bits[0], b->bits[1], bit - 1));
        
        if (a->bits[1] && b->bits[0])
            best = max(best, (1 << bit) | maxXor(a->bits[1], b->bits[0], bit - 1));
        
        if (best == 0) {
            if (a->bits[0] && b->bits[0])
                best = max(best, maxXor(a->bits[0], b->bits[0], bit - 1));
            
            if (a->bits[1] && b->bits[1])
                best = max(best, maxXor(a->bits[1], b->bits[1], bit - 1));
        }
        
        return best;
    }
};

class Solution {
public:
    trie* Trie = new trie();
    vector<vector<int>> child;
    vector<vector<pair<int,int>>> qs; // {val, index}
    vector<int> ans;
    void dfs(int root){
        if(root == -1) return;
        Trie->insert(root);
        for(auto &[val, i] : qs[root]){
            ans[i] = Trie->maxXorWith(val);
        }
        for(int &i : child[root]) dfs(i);
        Trie->erase(root);
    }
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        int n = parents.size();
        child.resize(n);
        qs.resize(n);
        ans.resize(queries.size());
        int root;
        for(int i = 0; i < n; i++){
            int p = parents[i];
            if(p == -1){
                root = i;
                continue;
            }
            child[p].push_back(i);
        }
        for(int i = 0; i < queries.size(); i++){
            qs[queries[i][0]].push_back({queries[i][1], i});
        }
        dfs(root);
        return ans;
    }       
};