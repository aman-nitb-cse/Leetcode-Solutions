// Last updated: 8/20/2026, 9:11:18 PM
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> v;
    void bt(int rem, int target, int curr = 9){
        if(target == 0 && rem == 0) {
            ans.push_back(v);
            return;
        }
        if(curr < 1 || target < 0) return;
        // skip
        bt(rem, target, curr - 1);

        // take
        v.push_back(curr);
        bt(rem - 1, target - curr, curr - 1);
        v.pop_back();
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        bt(k, n);
        return ans;
    }
};