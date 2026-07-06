// Last updated: 7/6/2026, 5:33:58 AM
class Solution {
public:
    int minOperations(string a, string b) {
        int n = a.size();

        if(n == 1 && a[0] == '1' && b[0] == '0') return -1;


        int cnt = 0;
        
        for(int i = 0; i < n; i++){
            if(a[i] == '0' && b[i] == '1'){
                a[i] = '1';
                cnt++;
            }
        }

        int k = 0;

        auto calc = [&](){
            cnt += k / 2;
            if(k & 1) cnt += 2;
            k = 0;
        };

        for(int i = 0; i < n; i++){
            if(a[i] == '1' && b[i] == '0'){
                k++;
            }
            else calc();
        }

        calc();

        return cnt;
    }
};