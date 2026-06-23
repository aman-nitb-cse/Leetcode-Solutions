// Last updated: 6/24/2026, 3:26:42 AM
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