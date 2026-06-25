// Last updated: 6/25/2026, 11:13:28 PM
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> freq;

        for(auto &s : arr) freq[s]++;

        for(auto &s : arr){
            if(freq[s] > 1) continue;
            if(k == 1) return s;
            k--;
        }
        return "";
    }
};