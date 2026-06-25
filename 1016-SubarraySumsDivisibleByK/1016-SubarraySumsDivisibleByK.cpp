// Last updated: 6/25/2026, 11:19:28 PM
class Solution {
public:
    int nC2(int n){
        return n * (n - 1) / 2;
    }
    int subarraysDivByK(vector<int>& nums, int k) {
        nums[0] = (nums[0] % k + k) % k;
        for(int i = 1; i < nums.size(); i++) nums[i] =  ((nums[i] + nums[i - 1]) % k + k) % k;

        vector <int> v(k);
        v[0] = 1;
        for(int &i : nums) v[i]++;
        

        int count = 0;
        for(int &i : v){
            count += nC2(i);
        }
        return count;
    }
};