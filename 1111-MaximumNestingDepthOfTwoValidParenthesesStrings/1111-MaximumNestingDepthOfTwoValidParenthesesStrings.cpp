// Last updated: 11/6/2026, 5:07:38 AM
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int d = 0;
        vector<int> ans;
        for (char& c : seq)
            if (c == '(') {
                ++d;
                ans.push_back(d % 2);
            } else {
                ans.push_back(d % 2);
                --d;
            }
        return ans;
    }
};