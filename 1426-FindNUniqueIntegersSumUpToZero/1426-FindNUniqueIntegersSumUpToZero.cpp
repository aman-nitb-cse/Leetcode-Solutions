// Last updated: 6/25/2026, 11:17:14 PM
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