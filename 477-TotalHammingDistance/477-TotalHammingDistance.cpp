// Last updated: 8/20/2026, 9:04:42 PM
class Solution {
public:
    int nC2(int n){ return n * (n - 1) / 2; }
    int totalHammingDistance(vector<int>& nums) {
        vector<int> v(32, 0);
        for(int &i : nums){
            for(int j = 0; i; j++){
                v[j] += (i&1);
                i >>= 1;
            }
        }
        int count = 0;
        for(int &i : v){
            count += i * (nums.size() - i); 
        }
        return count;
    }
};