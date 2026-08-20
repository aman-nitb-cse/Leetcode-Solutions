// Last updated: 8/20/2026, 9:15:56 PM
class Solution {
public:
    bitset<100000> used;
    vector<int> ans;
    bool bt(int n){
        if(ans.size() == (1 << n)) return true;
        int prev = ans.back();
        for(int i = 0; i < n; i++){
            prev ^= (1 << i);
            if(!used[prev]) {
                ans.push_back(prev);
                used.set(prev);
                if(bt(n)) return true;;
                used.reset(prev);
                ans.pop_back();
            }
            prev ^= (1 << i);
        }
        return false;
    }
    vector<int> grayCode(int n) {
        ans.push_back(0);
        used.set(0);
        bt(n);
        return ans;
    }
};