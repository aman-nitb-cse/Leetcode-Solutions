// Last updated: 6/25/2026, 11:11:06 PM
class Solution {
public:
    // log2(x)
    int depth(int x){
        if(x == 1) return 0;

        return 1 + depth(x >> 1);
    }

    // x >> 1
    int kthAnc(int x, int k){
        return x >> k;
    }

    int getLCA(int u, int v){

        if(depth(u) < depth(v)) swap(u, v);

        u = kthAnc(u, depth(u) - depth(v));

        while(u ^ v){
            u >>= 1;
            v >>= 1;
        }
        return u;
    }
    
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        
        vector<int> ans;

        for(auto &q : queries){
            int u = q[0], v = q[1];

            int LCA = getLCA(u, v);

            ans.push_back(depth(u) + depth(v) - 2 * depth(LCA) + 1);
        }

        return ans;
    }
};