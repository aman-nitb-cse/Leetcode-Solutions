// Last updated: 8/20/2026, 9:06:41 PM
class Solution {
public:
    int findNthDigit(int n) {
        if(n < 10) return n;
        long long count = 0;
        int i;
        for(i = 0; ; i++){
            count += 9 * pow(10, i) * (i + 1);

            if(n <= count) break;
        }

        int prev_count = count - 9 * pow(10, i) * (i + 1);
        int rem = n - prev_count;
        int step = (rem - 1) / (i + 1);
        int x = pow(10, i) + step;
        auto y = to_string(x);
        int z = (rem - 1) % (i + 1);

        return y[z] - '0';
    }
};