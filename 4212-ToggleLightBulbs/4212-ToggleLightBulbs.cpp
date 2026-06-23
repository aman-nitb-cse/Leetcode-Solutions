// Last updated: 6/24/2026, 3:28:07 AM
class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        bool arr[101] = {0};
        for(int &i : bulbs){
            arr[i] = !arr[i];
        }

        bulbs.clear();
        for(int i = 0; i < 101; i++){
            if(arr[i]) bulbs.push_back(i);
        }
        return bulbs;
    }
};