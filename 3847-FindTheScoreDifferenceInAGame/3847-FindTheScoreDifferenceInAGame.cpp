// Last updated: 11/6/2026, 4:36:06 AM
class Solution {
public:
    int scoreDifference(vector<int>& v) {
        int sum = 0;
        int sign = 1;
        for(int i = 0; i < v.size(); i++){
            if(i % 6 == 5) sign *= -1;
            if(v[i] & 1) sign *= -1;

            sum += sign * v[i];
        }
        return sum;
    }
};