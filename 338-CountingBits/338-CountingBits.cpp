// Last updated: 8/20/2026, 9:08:21 PM
class Solution {
public:
    int bits(int i){
        int sum = 0; 
        while(i){
            sum += (i&1);
            i = i >> 1;
        }
        return sum;
    }

    vector<int> countBits(int n) {
        vector <int> v;
        v.push_back(0);
        for(int i = 1; i <= n; i++){
            int Onebits = v[i >> 1] + (i&1);
            v.push_back(Onebits);
        }
        return v;
    }
};