// Last updated: 6/25/2026, 11:17:32 PM
class Solution {
public:
    bitset<27> bit;
    void toggle(string &s){
        for(char &c : s){
            bit.flip(c - 'a');
        }
    }
    int maxLength(vector<string>& arr, int i = 0) {
        if(i == arr.size()) return 0;

        // skip
        int skip = maxLength(arr, i + 1);

        bool canTake = true;
        auto _bit = bit;
        for(char &c : arr[i]){
            if(_bit[c - 'a']){
                canTake = false;
                break;
            }
            else _bit.set(c - 'a');
        }

        int take = 0;

        if(canTake){
            toggle(arr[i]);
            take = arr[i].size() + maxLength(arr, i + 1);
            toggle(arr[i]);
        }

        return max(skip, take);
    }
};