// Last updated: 6/24/2026, 3:30:31 AM
class Solution {
public:

    long long ans = 0;
    int k, n;
    string s;

    long long fact[11];

    unordered_set<string> st;

    long long ways(string s){

        ranges::sort(s);

        if(st.count(s)) return 0;

        st.insert(s);

        vector<int> cnt(10);

        for(char c : s) cnt[c - '0']++;

        long long res = 0;

        for(int first = 1; first <= 9; first++){

            if(!cnt[first]) continue;

            cnt[first]--;

            long long cur = fact[n - 1];

            for(int d = 0; d < 10; d++) cur /= fact[cnt[d]];

            res += cur;

            cnt[first]++;
        }

        return res;
    }

    void bt(int i){

        if(i > (n - 1) / 2){

            long long x = stoll(s);

            if(x % k == 0)
                ans += ways(s);

            return;
        }

        for(char c = '0' + !i; c <= '9'; c++){

            s[i] = s[n - 1 - i] = c;

            bt(i + 1);
        }
    }

    long long countGoodIntegers(int _n, int _k) {

        n = _n;
        k = _k;

        fact[0] = 1;

        for(int i = 1; i <= 10; i++)
            fact[i] = fact[i - 1] * i;

        s.assign(n, '0');

        bt(0);

        return ans;
    }
};