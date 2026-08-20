// Last updated: 8/20/2026, 9:06:11 PM
class Tries {
public:
    Tries* bit[2] = {NULL};

    void insert(int x){
        auto node = this;

        for(int i = 31; i >= 0; i--){
            int b = (x >> i) & 1;
            if(!node->bit[b]) node->bit[b] = new Tries();
            node = node->bit[b];
        }
    }
};

int Xor(Tries* a, Tries* b, int i = 31){
    if(!a || !b || i < 0) return 0;

    auto a0 = a->bit[0];
    auto a1 = a->bit[1];
    auto b0 = b->bit[0];
    auto b1 = b->bit[1];

    // prefer XOR = 1
    
    if(a0 && b1 || a1 && b0)
        return (1<<i) + max(Xor(a0,b1,i-1), Xor(a1,b0,i-1));

    // otherwise XOR = 0
    return max(Xor(a0,b0,i-1), Xor(a1,b1,i-1));
}

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        auto node = new Tries();

        for(auto &i : nums) node->insert(i);

        return Xor(node, node);
    }
};