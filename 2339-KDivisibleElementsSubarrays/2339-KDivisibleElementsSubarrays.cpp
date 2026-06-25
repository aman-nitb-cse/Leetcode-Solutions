// Last updated: 6/25/2026, 11:12:28 PM
class Solution {
public:

    using ull = unsigned long long;

    const ull base = 1e6 + 3;

    int countDistinct(vector<int>& nums, int k, int p) {

        int n = nums.size();

        unordered_set<ull> st;

        int count = 0;

        for(int i = 0; i < n; i++){


            ull h = 0;

            int divs = 0;

            for(int j = i; j < n; j++){

                if(nums[j] % p == 0)
                    divs++;

                if(divs > k)
                    break;

                h = h * base + nums[j] + 1;

                ull key = (h << 20) | (j - i + 1);

                count += st.insert(key).second;
            }
        }

        return count;
    }
};