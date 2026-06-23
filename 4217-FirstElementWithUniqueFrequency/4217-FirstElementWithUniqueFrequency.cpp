// Last updated: 6/24/2026, 3:27:59 AM
class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int> hash;
        for(int &i : nums) hash[i]++;

        vector<vector<int>> v(nums.size() + 1);
        for(auto i = hash.begin(); i != hash.end(); i++){
            v[i->second].push_back(i->first);
        }

        unordered_set<int> st;
        for(vector<int>& t : v){
            if(t.size() == 1) st.insert(t[0]);
        }

        for(int &i : nums){
            if(st.find(i) != st.end()){
                return i;
            }
        }
        return -1;
    }
};