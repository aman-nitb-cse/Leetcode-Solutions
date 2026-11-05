// Last updated: 11/6/2026, 5:11:30 AM
class Solution {
public:
    int sum = 0;
    vector<int> w;
    Solution(vector<int>& _w) : w(_w){
        for(int i = 1; i < w.size(); i++){
            w[i] += w[i - 1];
        }
        sum = w.back();
        srand(time(0));
    }
    
    int pickIndex() {
        return ranges::upper_bound(w, rand() % sum) - w.begin();
    }
};