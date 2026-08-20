// Last updated: 8/20/2026, 9:12:38 PM
class Solution {
public:
    vector<int> twoSum(vector<int>& v, int k) {
        int s = 0, e = v.size() - 1;
        while(s <= e and e < v.size()){
            if(v[s] + v[e] == k) return {s + 1, e + 1};
            if(v[s] + v[e] > k) e--;
            else s++;
        }
        return {s + 1, e + 1};
    }
};