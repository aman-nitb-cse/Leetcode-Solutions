// Last updated: 6/24/2026, 3:31:28 AM
class Solution {
public:

    using ull = unsigned long long;

    const ull base = 1e6 + 3;

    int countMatchingSubarrays(vector<int>& nums, vector<int>& pat) {

        int m = pat.size(), n = nums.size();

        auto get = [&](int i){

            return (nums[i + 1] > nums[i]) - (nums[i + 1] < nums[i]) + 2;
        };

        ull ph = 0;

        for(int &x : pat){

            ph = ph * base + x + 2;
        }

        ull h = 0;

        ull pw = 1;

        for(int i = 0; i < m; i++){

            h = h * base + get(i);

            pw *= base;
        }

        int count = (h == ph);

        for(int i = m; i < n - 1; i++){

            h = h * base + get(i);

            h -= pw * get(i - m);

            count += (h == ph);
        }

        return count;
    }
};