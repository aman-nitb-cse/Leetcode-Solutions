// Last updated: 11/6/2026, 5:11:16 AM
class RLEIterator {
public:
    vector<int> enc;
    int i = 0;
    RLEIterator(vector<int>& _enc) : enc(_enc) {}

    int next(int n) {
        while(i < enc.size()){
            if(enc[i] >= n){
                enc[i] -= n;
                return enc[i + 1];
            }
            else{
                n -= enc[i];
                enc[i] = 0;
                i += 2;
            }
        }
        return -1;
    }
};