// Last updated: 6/24/2026, 3:28:41 AM
class Solution {
public:
    using ll = unsigned long long;
    ll f(ll n){
        ll pw = 10, cnt = 0;
        while(10 * pw < n){
            ll left = (n / pw) / 100;
            ll right = n % (pw / 10);

            int real = (n * 10 / pw) % 1000;
            
            for(int d = 0; d <= 9; d++){

                // \/
                for(int i = d + 1; i <= 9; i++){

                    for(int j = d + 1; j <= 9; j++){

                        int x = 100 * i + 10 * d + j;

                        if(x > real){

                            // left : [0, left)
                            // rd | right : [0, pw / 10)

                            cnt += left * pw / 10;
                        }
                        else if(x < real){

                            // left : [0, left]
                            // rd | right : [0, pw / 10)

                            cnt += (left + 1) * pw / 10;
                        }
                        else {
                            // left : [0, left)
                            // right : [0, pw / 10)
                            cnt += left * pw / 10;

                            // left : left
                            // right : [0, right]
                            cnt += right + 1;
                        }
                    }
                }

                // /\.
                    
                for(int i = d - 1; i >= 0; i--){
                        
                    for(int j = d - 1; j >= 0; j--){

                        int x = 100 * i + 10 * d + j;
                            
                        if(x > real){

                            // left : [0, left)
                            // rd | right : [0, pw / 10)

                            cnt += (left - !i) * pw / 10;
                        }
                        else if(x < real){

                            // left : [0, left]
                            // rd | right : [0, pw)

                            cnt += (left + 1 - !i) * pw / 10;
                        }
                        else {
                            // left : [0, left)
                            // right : [0, pw)
                            cnt += (left - !i) * pw / 10;

                            // left : left
                            // right : [0, right]
                            if(i || left) cnt += right + 1;
                        }
                    }
                }
            }

            pw *= 10;
        }
        return cnt;
    }
    ll totalWaviness(ll l, ll r) {
        return f(r) - f(l - 1);
    }
};