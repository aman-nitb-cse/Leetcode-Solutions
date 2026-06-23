// Last updated: 6/24/2026, 3:28:18 AM
class Solution {
public:
    using ll = long long;

    long long ways(int ones, int zeros){

        if(ones == 0)
            return 0;

        int n = ones + zeros - 1;
        int r = min(ones - 1, zeros);

        long long ans = 1;

        for(int i = 1; i <= r; i++)
            ans = ans * (n - r + i) / i;

        return ans;
    }

    long long nthSmallest(long long n, int k) {
        if(k == 0) return 0;
        ll cnt = 0;
        int i = 0;
        while(true){
            ll c = ways(k, i);
            if(c + cnt >= n) break;
            cnt += c;
            i++;
        }
        long long x = nthSmallest(n - cnt, k - 1);
        return x | 1LL << (k - 1 + i);
    }
};

/*
k = 3;

(ones, zeros)

111 (k - 1, 0)

1011 (k - 1, 1)
1101 
1110

10011 (k - 1, 2)
10101
10110
11001
11010
11100

100011
100101
100110
101001
101010
101100
110100
111000


*/