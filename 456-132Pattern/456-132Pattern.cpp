// Last updated: 8/20/2026, 9:05:22 PM
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefMin(n);

        prefMin[0] = nums[0];
        for(int i = 1; i < n; i++)
            prefMin[i] = min(prefMin[i - 1], nums[i]);

        set<int> st;
        st.insert(nums.back());

        auto justPrev = [&](int x){
            auto it = st.lower_bound(x);

            if(it == st.begin()) return INT_MIN;

            --it;
            return *it;
        };

        for(int i = n - 2; i > 0; i--){

            if(prefMin[i - 1] < justPrev(nums[i])) return true;

            st.insert(nums[i]);
        }

        return false;
    }
};