// Last updated: 8/20/2026, 8:51:47 PM
class Solution {
public:
    double total = 0, want = 0; 
    
    double nCr(int n, int r) {
        double res = 1;
        for (int k = 1; k <= r; k++) {
            res = res * (n - k + 1) / k;
        }
        return res;
    }

    void f(vector<int>& b, int i, int rem, int dif, double ways){

        if(rem < 0) return;

        if(i == b.size()){
            if(rem == 0) {
                total += ways;
                if(dif == 0) {
                    want += ways;
                }
            }
            return;
        }

        for(int j = 0; j <= b[i]; j++){
            int ndif = dif;

            if(j == 0) ndif++;
            else if(j == b[i]) ndif--;

            f(b, i + 1, rem - j, ndif, ways * nCr(b[i], j)); 
        }
    }

    double getProbability(vector<int>& b) {
        int n = 0;
        for(int &i : b) n += i;
        n >>= 1;
        
        f(b, 0, n, 0, 1.0); 
        
        return want / total;
    }
};