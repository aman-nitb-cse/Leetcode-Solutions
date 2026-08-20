// Last updated: 8/20/2026, 9:17:54 PM
class Solution {
public:
    vector<vector<string>> ans;
    vector<string> v;
    unordered_set<int> dig1;
    unordered_set<int> dig2;
    unordered_set<int> col;

    void put(int r, int c){
        v[r][c] = 'Q';
        dig1.insert(r - c);
        dig2.insert(r + c);
        col.insert(c);
    }

    void remove(int r, int c){
        v[r][c] = '.';
        dig1.erase(r - c);
        dig2.erase(r + c);
        col.erase(c);
    }
    
    bool check(int r, int c){
        return dig1.count(r - c) == 0 && dig2.count(r + c) == 0 && col.count(c) == 0;
    }

    void solve(int n, int r = 0){
        if(r == n){
            ans.push_back(v);
            return;
        }

        for(int i = 0; i < n; i++){
            if(check(r, i)){
                put(r, i);
                solve(n, r + 1);
                remove(r, i);
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        v.assign(n, string(n, '.'));
        solve(n);
        return ans;
    }
};