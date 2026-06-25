// Last updated: 6/25/2026, 11:17:16 PM
class Solution {
public:
    bool isPossibleDivide(vector<int>& hand, int k) {
        int n = hand.size();
        if(n % k) return false;

        map<int,int> mp;

        for(int &i : hand) mp[i]++;

        while(!mp.empty()){
            int mini = mp.begin()->first; 
            mp.begin()->second--;
            if(mp.begin()->second == 0) mp.erase(mp.begin());

            for(int i = mini + 1; i < mini + k; i++){
                auto it = mp.find(i);
                if(it != mp.end()) {
                    it->second--;
                    if(it->second == 0) mp.erase(it);
                }
                else return false;
            }
        }
        return true;
    }
};