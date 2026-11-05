// Last updated: 11/6/2026, 5:21:26 AM
class Solution {
public:
    int threeSumClosest(vector<int>& v, int k) {
        int ans = v[0] + v[1] + v[2];
        sort(v.begin(), v.end());
        for(int i = 0; i < v.size(); i++){
            int s = i + 1, e = v.size() - 1;
            while(s < e){
                int sum = v[i] + v[s] + v[e];
                if(abs(sum - k) < abs(ans - k)) ans = sum;
                if(sum < k) s++;
                else if(sum == k) return k;
                else e--;
            }
        }
        return ans;
    }
};