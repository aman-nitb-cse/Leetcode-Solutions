// Last updated: 11/6/2026, 5:05:08 AM
class Solution {
public:
    vector<int> sumZero(int n) {
        vector <int> v;
        for(int i = 1; i < n; i++){
            v.push_back(i);
        }
        v.push_back(- (n) * (n - 1) / 2);
        return v;
    }
};