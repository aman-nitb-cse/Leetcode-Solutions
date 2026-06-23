// Last updated: 6/24/2026, 3:29:19 AM
class Solution {
public:
    const int m = 1e9 + 7;
    long long binexp(long long a, long long b) {
        long long res = 1;
        a %= m;
        while (b > 0) {
            if (b & 1) res = (res * a) % m;
            a = (a * a) % m;
            b >>= 1;
        }
        return res;
    }
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int size = ceil(sqrt(n));

        unordered_map<int, vector<vector<int>>> kmp;

        for(auto &q : queries){
            if(q[2] >= size){
                for(int i = q[0]; i <= q[1]; i += q[2]){
                    nums[i] = (1LL * nums[i] * q[3]) % m;
                }
            } else {
                kmp[q[2]].push_back(q);
            }
        }
        for(auto& [k, Q] : kmp){
            vector<long long> diff(n, 1);

            for(auto& q : Q){
                diff[q[0]] = (1LL * diff[q[0]] * q[3]) % m;

                int steps = (q[1] - q[0]) / k;
                int next = q[0] + (steps + 1) * k;

                if(next < n) diff[next] = (1LL * diff[next] * binexp(q[3], m - 2)) % m;
            }

            // cummulative
            for(int i = 0; i < n; i++){
                if(i >= k) diff[i] = (1LL * diff[i] * diff[i - k]) % m;
            }

            // apply
            for(int i = 0; i < n; i++){
                nums[i] = (1LL * nums[i] * diff[i]) % m;
            }
        }
        int ans = 0;
        for(int &i : nums) ans ^= i;
        return ans;
    }
};