// Last updated: 11/6/2026, 5:03:47 AM
class Solution {
public:
    int findTheDistanceValue(vector<int>& a, vector<int>& b, int d) {
        int diff[20001] = {};

        for(int &i : b){
            int l = max(0, i - d + 1000);
            int r = i + d + 1000;

            diff[l]++;
            if(r + 1 < 20001) diff[r + 1]--;
        }


        for(int i = 1; i < 20001; i++){
            diff[i] += diff[i - 1];
        }

        int cnt = 0;
        for(int &i : a){
            cnt += !diff[i + 1000];
        }

        return cnt;
    }
};

// difference array O(m + n)