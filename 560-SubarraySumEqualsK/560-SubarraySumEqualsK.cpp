// Last updated: 8/20/2026, 9:02:57 PM
class Solution {
public:
    int subarraySum(vector<int>& v, int k) {
        for(int i = 1; i < v.size(); i++) v[i] += v[i - 1];
        int count = 0;
        unordered_map <int, int> hash;
        for(int &i : v){
            int need = (i - k);
            if(hash.find(need) != hash.end()) count += hash[need];
            if(i == k) count++;
            hash[i]++;
        }
        return count;
    }
};