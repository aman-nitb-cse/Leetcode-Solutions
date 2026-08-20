// Last updated: 8/20/2026, 9:06:40 PM
class Solution {
public:
    int countOneBits(int n) {
        int sum = 0;
        while(n){
            sum += (n&1);
            n = n >> 1;
        }
        return sum;
    }
    vector<string> readBinaryWatch(int k) {
        vector<string> s;
        for(int i = 0; i < (1 << 10) - 1; i++){
            if(countOneBits(i) != k) continue;
            int temp = i, h = 0, m = 0;
            for(int j = 0; j < 6; j++){
                m += (temp&1) * (1 << j);
                temp >>= 1;
            }
            for(int j = 0; j < 4; j++){
                h += (temp&1) * (1 << j);
                temp >>= 1;
            }
            if(m >= 60 or h >= 12) continue;
            if(m < 10) s.push_back(to_string(h) + ":0" + to_string(m));
            else s.push_back(to_string(h) + ":" + to_string(m));
        }
        return s;
    }
};