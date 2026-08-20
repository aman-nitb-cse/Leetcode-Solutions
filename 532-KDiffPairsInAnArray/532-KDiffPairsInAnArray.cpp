// Last updated: 8/20/2026, 9:03:24 PM
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(nums.size() == 1) return 0;
        int count = 0;
        set <int> st;
        unordered_set <int> isCounted;
        for(int &i : nums){
            if(st.find(i) != st.end() and k == 0 and isCounted.find(i) == isCounted.end()){
                count++;
                isCounted.insert(i);
            }
            st.insert(i);
        }
        if(k == 0) return count;
        auto s = st.begin();
        auto e = st.begin(); e++;
        while( e != st.end()){
            int d = *e - *s;
            if(d == k) count++;

            if(d > k) s++;
            else e++;
        }
        return count;
    }
};