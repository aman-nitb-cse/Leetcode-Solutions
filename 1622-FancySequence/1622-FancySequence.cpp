// Last updated: 11/6/2026, 5:00:54 AM
class Fancy {
public:
    vector<long long> v;
    long long mul = 1, add = 0;
    const int MOD = 1e9+7;

    long long modInv(long long x){
        long long res = 1, p = MOD-2;
        while(p){
            if(p&1) res = res * x % MOD;
            x = x * x % MOD;
            p >>= 1;
        }
        return res;
    }

    void append(int val) {
        long long x = (val - add + MOD) % MOD;
        x = x * modInv(mul) % MOD;
        v.push_back(x);
    }
    
    void addAll(int val) {
        add = (add + val) % MOD;
    }
    
    void multAll(int m) {
        mul = mul * m % MOD;
        add = add * m % MOD;
    }
    
    int getIndex(int i) {
        if(i >= v.size()) return -1;
        return (v[i] * mul + add) % MOD;
    }
};