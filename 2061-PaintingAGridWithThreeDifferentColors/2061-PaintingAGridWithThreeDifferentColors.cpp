// Last updated: 6/30/2026, 2:16:36 PM
class Solution {
    using ll = long long;
    using Matrix = vector<vector<ll>>;

    Matrix mul(Matrix& A, Matrix& B) {
        int n = A.size();
        int m = B[0].size();
        int p = B.size();

        Matrix C(n, vector<ll>(m));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < p; k++) {
                if(!A[i][k]) continue;
                for (int j = 0; j < m; j++) {
                    C[i][j] += A[i][k] * B[k][j];
                    C[i][j] %= mod;
                }
            }
        }

        return C;
    }

    Matrix power(Matrix A, ll n) {
        int sz = A.size();

        Matrix res(sz, vector<ll>(sz));

        for (int i = 0; i < sz; i++)
            res[i][i] = 1;

        while (n) {
            if (n & 1)
                res = mul(res, A);
            A = mul(A, A);
            n >>= 1;
        }

        return res;
    }
public:
    vector<string> v;
    const int mod = 1e9 + 7;
    void f(int m, string s){
        if(m == 0) {
            v.push_back(s);
            return;
        }
        for(char c : {'a', 'b', 'c'}){
            if(s.empty() || s.back() != c){
                f(m - 1, s + c);
            }
        }
    }
    bool check(int i, int j){
        for(auto&& [x, y] : views::zip(v[i], v[j])){
            if(x == y) return false;
        }
        return true;
    }
    int colorTheGrid(int m, int n) {
        
        f(m, "");

        int N = v.size();

        Matrix T (N, vector<ll> (N));

        for(int i = 0; i < N; i++){
            for(int j = 0; j < i; j++){
                T[i][j] = T[j][i] = check(i, j);
            }
        }

        Matrix base(N, vector<ll> (1, 1));

        T = power(T, n - 1);
        T = mul(T, base);

        int ans = 0;
        for(int i = 0; i < N; i++){
            ans += T[i][0];
            ans %= mod;
        }
        return ans;
    }
};