// Last updated: 6/25/2026, 11:12:32 PM
class Solution {
public:

    using ull = unsigned long long;

    const ull BASE = 131;

    long long sumScores(string s) {

        int n = s.size();

        vector<ull> hash(n), power(n, 1);

        hash[0] = s[0];

        for(int i = 1; i < n; i++){

            hash[i] = hash[i - 1] * BASE + s[i];

            power[i] = power[i - 1] * BASE;
        }

        auto get = [&](int l, int r){

            if(l == 0) return hash[r];

            return hash[r] - hash[l - 1] * power[r - l + 1];
        };

        long long ans = 0;

        for(int i = 0; i < n; i++){

            int start = 0, end = n - i;

            while (start < end){

                int mid =  (start + end + 1) / 2;

                if(get(0, mid - 1) == get(i, i + mid - 1)) start = mid;

                else end = mid - 1;
            }

            ans += start;
        }

        return ans;
    }
};