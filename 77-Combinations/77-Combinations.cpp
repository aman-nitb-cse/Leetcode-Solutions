// Last updated: 8/20/2026, 9:16:41 PM
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    void backtrack(int s, int e, int k){
        if(k == 0){
            // ans at leaf in backtrack
            ans.push_back(curr);
            return;
        }
        while(s <= e - k + 1){

            // take this value
            curr.push_back(s);

            // go ahead
            backtrack(++s, e, k - 1);

            // undo
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        backtrack(1, n, k);
        return ans;
    }
};