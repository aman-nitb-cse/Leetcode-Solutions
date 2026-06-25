// Last updated: 6/25/2026, 11:12:30 PM
class Solution {
public:
    int largestInteger(int n) {
        vector<int> v;
        while(n){
            v.push_back(n % 10);
            n /= 10;
        }
        reverse(v.begin(), v.end());
        for(int i = 0; i < v.size(); i++){
            int maxi = i;
            for(int j = i + 1; j < v.size(); j++){
                if((v[i] & 1) == (v[j] & 1) && v[j] >= v[maxi]) maxi = j;
            }

            if(maxi != i) swap(v[i], v[maxi]);
        }

        n = 0;
        for(int &i : v){
            n = n * 10 + i;
        }
        return n;
    }
};