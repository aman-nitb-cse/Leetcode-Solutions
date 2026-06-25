// Last updated: 6/25/2026, 11:16:48 PM
class Solution {
public:
    // int count_bits(int n){
    //     int sum = 0;
    //     while(n){
    //         sum += n & 1;
    //         n >>= 1;
    //     }
    //     return sum;
    // }

    vector<int> sortByBits(vector<int>& v) {
        unordered_map <int, int> bits;
        int maxi = v[0];
        for(int &i : v) maxi = max(maxi, i);
        bits[0] = 0;
        for(int i = 1; i <= maxi; i++){
            bits[i] = bits[i >> 1] + (i & 1);
        }
        for(int i = 0; i < v.size(); i++){
            int minbits = i;
            for(int j = i + 1; j < v.size(); j++){
                if(bits[v[j]] < bits[v[minbits]] or (bits[v[j]] == bits[v[minbits]] and v[j] < v[minbits])) minbits = j; 
            }
            swap(v[minbits], v[i]);
        }
        return v;
    }
};