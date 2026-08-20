// Last updated: 8/20/2026, 9:01:22 PM
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;

        auto r = ranges::lower_bound(arr, x);
        auto l = r - 1;


        while(ans.size() < k){
            if(r != arr.end() && (l + 1 == arr.begin() || *r - x < x - *l)) ans.push_back(*r++);
            else ans.push_back(*l--);
        }
        ranges::sort(ans);
        return ans;
    }
};