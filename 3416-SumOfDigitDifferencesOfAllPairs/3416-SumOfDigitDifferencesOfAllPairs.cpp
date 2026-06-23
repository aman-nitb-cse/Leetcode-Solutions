// Last updated: 6/24/2026, 3:30:49 AM
class Solution {
public:
    long long nC2(long long n){
        return n * (n - 1) / 2;
    }
    long long sumDigitDifferences(vector<int>& nums) {
        int n = to_string(nums.front()).size(), size = nums.size();
        vector <vector<int>> v(n, vector<int> (10));

        for(int &i : nums){
            for(int j = 0; i; j++){
                v[j][i % 10]++;
                i /= 10;
            }
        }
        long long sum = 0;
        for(vector<int> &a : v){
            for(int &i : a){
                sum += nC2(i);
            }
        }
        return n * nC2(size) - sum;
    }
};