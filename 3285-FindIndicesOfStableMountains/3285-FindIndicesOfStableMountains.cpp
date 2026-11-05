// Last updated: 11/6/2026, 4:44:46 AM
class Solution {
public:
    vector<int> stableMountains(vector<int>& v, int k) {
        int j = 0;
        for(int i = 0; i < v.size() - 1; i++){
            if(v[i] > k) v[j++] = i + 1;
        }
        v.resize(j);
        return v;
    }
};