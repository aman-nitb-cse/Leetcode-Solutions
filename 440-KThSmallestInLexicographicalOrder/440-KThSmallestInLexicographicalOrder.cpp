// Last updated: 8/20/2026, 9:05:50 PM
class Solution {
public:

    long long count(long long n, long long curr){

        long long next = curr + 1;

        long long cnt = 0;

        while(curr <= n){

            cnt += min(n + 1LL, next) - curr;

            curr *= 10;
            next *= 10;
        }

        return cnt;
    }

    int findKthNumber(int n, int k) {

        long long curr = 1;

        k--;

        while(k){

            long long cnt = count(n, curr);

            if(cnt <= k){

                curr++;

                k -= cnt;
            }
            else{

                curr *= 10;

                k--;
            }
        }

        return curr;
    }
};