// Last updated: 6/25/2026, 11:36:59 PM
class Solution {
public:

    using ull = unsigned long long;

    ull base = 131;

    int findLength(vector<int>& a, vector<int>& b) {

        int n = b.size();

        for(int k = min(a.size(), b.size()); k > 0; k--){

            unordered_set<ull> st;

            ull h = 0;
            ull pw = 1;

            // first window of a

            for(int i = 0; i < k; i++){

                h = h * base + a[i] + 1;

                pw *= base;
            }

            st.insert(h);

            // rolling hashes of a

            for(int i = k; i < a.size(); i++){

                h = h * base + a[i] + 1;

                h -= pw * (a[i - k] + 1);

                st.insert(h);
            }

            // hashes of b

            h = 0;

            for(int i = 0; i < k; i++){

                h = h * base + b[i] + 1;
            }

            if(st.count(h)) return k;

            for(int i = k; i < b.size(); i++){

                h = h * base + b[i] + 1;

                h -= pw * (b[i - k] + 1);

                if(st.count(h)) return k;
            }
        }

        return 0;
    }
};