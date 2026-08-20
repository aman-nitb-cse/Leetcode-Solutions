// Last updated: 8/20/2026, 9:17:46 PM
class Solution {
public:
    unordered_set<int> dig1;
    unordered_set<int> dig2;
    unordered_set<int> col;
    int ans = 0;

    void put(int r, int c) {
        dig1.insert(r - c);
        dig2.insert(r + c);
        col.insert(c);
    }

    void remove(int r, int c) {
        dig1.erase(r - c);
        dig2.erase(r + c);
        col.erase(c);
    }

    bool check(int r, int c) { 
        return !dig1.count(r - c) && !dig2.count(r + c) && !col.count(c); 
    }

    void solve(int n, int r = 0) {
        if (r == n) {
            ans++;
            return;
        }

        for (int i = 0; i < n; i++) {
            if (check(r, i)) {
                put(r, i);
                solve(n, r + 1);
                remove(r, i);
            }
        }
    }

    int totalNQueens(int n) {
        solve(n);
        return ans;
    }
};