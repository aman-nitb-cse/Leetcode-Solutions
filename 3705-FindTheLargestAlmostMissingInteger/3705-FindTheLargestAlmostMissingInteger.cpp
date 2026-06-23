// Last updated: 6/24/2026, 3:30:08 AM
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        map <int, int> hash;
        for(int i = 0; i <= nums.size() - k; i++){
            unordered_set <int> st;
            for(int j = i; j < i + k; j++){
                st.insert(nums[j]);
            }
            for(int i : st) hash[i]++;
        }

        for(auto i = hash.rbegin(); i != hash.rend(); i++){
            if(i->second == 1) return i->first;
        }
        return -1;
    }
};