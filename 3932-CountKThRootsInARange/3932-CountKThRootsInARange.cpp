// Last updated: 11/6/2026, 4:33:08 AM
class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        if(k == 1) return r - l + 1;
        int count = 0;
        for(int i = 0; ; i++){
            int x = pow(i, k);
            if(x > r) return count;
            if(x >= l) count++;
        }
        return count;
    }
};

// how many x^k exist b/w [l, r]