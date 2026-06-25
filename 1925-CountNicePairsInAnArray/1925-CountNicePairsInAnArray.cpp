// Last updated: 6/25/2026, 11:14:45 PM
class Solution {
public:
    long long rev(int n){
        long long num = 0;
        while(n){
            num = num * 10 + n % 10;
            n /= 10;
        }
        return num;
    }
    long long nC2(long long n){ 
        return n * (n - 1) / 2; 
    }
    int countNicePairs(vector<int>& nums) {
        
        unordered_map <int, int> hash;

        for(int &i : nums) {
            i -= rev(i);
            hash[i]++;
        }

        long long count = 0;
        for(auto &i : hash) count += nC2(i.second);
        return count % 1000000007;
    }
};