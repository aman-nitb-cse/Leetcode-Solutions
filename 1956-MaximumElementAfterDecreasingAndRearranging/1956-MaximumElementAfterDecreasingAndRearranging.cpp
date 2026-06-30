// Last updated: 6/30/2026, 2:16:56 PM
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        ranges::sort(arr);
        arr.front() = 1;
        for(int i = 1; i < arr.size(); i++){
            arr[i] = min(arr[i], arr[i - 1] + 1);
        }
        return arr.back();
    }
};