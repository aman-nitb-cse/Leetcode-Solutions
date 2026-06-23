// Last updated: 6/24/2026, 3:31:43 AM
class Solution {
public:
    bool areSimilar(vector<vector<int>>& m, int k) {
        int n = m[0].size();
        k %= n;

        for(int i = 0; i < m.size(); i++){
            int ls = k;
            if(i & 1) ls = n - k;

            vector<int> temp = m[i];

            ranges::rotate(temp, temp.begin() + ls);

            if(temp != m[i]) return false;
        }
        return true;
    }
};