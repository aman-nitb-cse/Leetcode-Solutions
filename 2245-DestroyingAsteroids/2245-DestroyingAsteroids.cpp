// Last updated: 6/25/2026, 11:12:56 PM
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& arr) {
        ranges::sort(arr);
        unsigned long long m = mass;
        for(int &i : arr){
            if(i <= m) m += i;
            else return false;
        }
        return true;
    }
};