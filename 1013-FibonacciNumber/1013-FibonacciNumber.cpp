// Last updated: 6/25/2026, 11:19:31 PM
class Solution {
    using Matrix = vector<vector<long long>>;
    Matrix mul(Matrix &A, Matrix &B){
        int n = A.size();
        int m = B[0].size();
        int p = B.size();

        Matrix C(n, vector<long long>(m));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                for(int k = 0; k < p; k++){
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }

        return C;
    }

    Matrix power(Matrix A, long long n){
        Matrix res = {
            {1, 0},
            {0, 1}
        };

        while(n){
            if(n & 1) res = mul(res, A);
            A = mul(A, A);
            n >>= 1;
        }

        return res;
    }
public:
    int fib(int n) {

        if(n == 0) return 0;

        Matrix T = {{1, 1}, {1, 0}};

        Matrix m = {{1}, {0}};

        T = power(T, n - 1);

        Matrix M = mul(T, m);

        return M[0][0];
    }
};