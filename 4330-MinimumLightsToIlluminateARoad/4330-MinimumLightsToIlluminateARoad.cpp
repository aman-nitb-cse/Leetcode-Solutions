// Last updated: 6/24/2026, 3:26:26 AM
class Solution {
public:
    int minLights(vector<int>& L) {
        vector<int> diff(L.size());

        int n = L.size();

        for(int i = 0; i < n; i++){
            if(L[i]){
                diff[max(i - L[i], 0)] += 1;
                if(i + L[i] + 1 < n) diff[i + L[i] + 1] += -1;
            }
        }

        // debug
        // for(int &i : diff) cout << i << ' ';

        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += diff[i];

            
            diff[i] = sum;
        }

        int cnt = 0, ans = 0;

        for(int &i : diff){
            if(i){
                ans += (cnt + 2) / 3;
                cnt = 0;
            }
            else cnt++;
        }
        ans += (cnt + 2) / 3;
        return ans;
    }
};












