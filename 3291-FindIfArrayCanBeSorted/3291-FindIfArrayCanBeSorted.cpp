// Last updated: 6/24/2026, 3:31:22 AM
class Solution {
public:
    bool canSortArray(vector<int>& v) {
        unordered_map <int, int> bits;
        int maxi = v[0];
        for(int &i : v) maxi = max(maxi, i);
        bits[0] = 0;
        for(int i = 1; i <= maxi; i++){
            bits[i] = bits[i >> 1] + (i & 1);
        }

        for(int i = v.size() - 1; i >= 0; i--){
            for(int j = 0; j < i; j++){
                if(v[j + 1] < v[j]){
                    if(bits[v[j + 1]] == bits[v[j]]) swap(v[j], v[j + 1]);
                    else return false;
                } 
            }
        }
        return true;
    }
};