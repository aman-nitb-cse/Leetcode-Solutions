// Last updated: 8/20/2026, 9:02:10 PM
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int start = 0;
        int size = INT_MAX;

        multiset<pair<int,int>> st;
        for(int i = 0; i < nums.size(); i++) st.insert({nums[i].back(), i});

        while(true){
            auto last = prev(st.end()), first = st.begin();
            int i = last->second, e = last->first, s = first->first;

            if(e - s <= size){
                start = s;
                size = e - s;
            } 


            st.erase(last);
            nums[i].pop_back();
            if(nums[i].empty()) break;
            st.insert({nums[i].back(), i});
        }
        return {start, start + size};
    }
};