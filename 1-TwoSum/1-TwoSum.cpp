// Last updated: 8/20/2026, 9:20:56 PM
class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) {
        int n = v.size();
        unordered_map <int, int> hash;
        for(int i = 0; i < n; i++) hash[v[i]] = i;
        for(int i = 0; i < n; i++){
            int need = target - v[i];
            if(hash.find(need) != hash.end()){ // found
                if(need == v[i] and i != hash[need]) return {i, hash[need]};
                if(need != v[i]) return {i, hash[need]}; 
            }
        }
        return {};
    }
};