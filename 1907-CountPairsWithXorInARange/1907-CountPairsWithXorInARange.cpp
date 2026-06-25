// Last updated: 6/25/2026, 11:14:48 PM
class Trie {
public:
    Trie* bits[2] = {};
    int cnt = 0;

    void insert(int x){
        auto node = this;

        for(int i = 14; i >= 0; i--){

            int b = (x >> i) & 1;

            if(!node->bits[b]) node->bits[b] = new Trie();

            node = node->bits[b];
            node->cnt++;
        }
    }

    int count(int x, int k){
        auto node = this;

        int ans = 0;

        for(int i = 14; i >= 0 && node; i--){

            int xb = (x >> i) & 1;
            int kb = (k >> i) & 1;

            if(kb){

                if(node->bits[xb])
                    ans += node->bits[xb]->cnt;

                node = node->bits[xb ^ 1];
            }
            else{

                node = node->bits[xb];
            }
        }

        return ans;
    }
};

class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {

        Trie* root = new Trie();

        int ans = 0;

        for(int &x : nums){

            ans += root->count(x, high + 1);
            ans -= root->count(x, low);

            root->insert(x);
        }

        return ans;
    }
};