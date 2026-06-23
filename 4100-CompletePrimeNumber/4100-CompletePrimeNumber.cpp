// Last updated: 6/24/2026, 3:28:52 AM
class Solution {
public:
    bool isPrime(int n){
        if(n <= 1) return false;

        for(int i = 2; i * i <= n; i++){
            if(n % i == 0) return false;
        }
        return true;
    }
    bool completePrime(int num) {
        string s = to_string(num);

        for(int n = 0, i = 0; i < s.size(); i++){
            n = (s[i] - '0') + n * 10;
            if(!isPrime(n)) return false;
        }
        ranges::reverse(s);
        for(int n = 0, i = 0; i < s.size(); i++){
            n += (s[i] - '0') * pow(10, i);
            if(!isPrime(n)) return false;
        }
        return true;
    }
};