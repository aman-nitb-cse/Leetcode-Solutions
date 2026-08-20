// Last updated: 8/20/2026, 8:50:58 PM
class Solution {
public:
    bool isTransformable(string s, string t) {

        auto os = s, ot = t;

        for(int d = 0; d <= 9; d++){
            string ns = "", nt = "";

            // cout << d << endl;

            int dt = 0, ds = 0;
            for(int i = 0; i < s.size(); i++){

                if(s[i] == d + '0') ds++;
                else ns += s[i];

                if(t[i] == d + '0') dt++;
                else nt += t[i];

                // cout << ds << ' ' << dt << endl;


                if(ds > dt) return false;
            }

            s = ns;
            t = nt;
            // cout << s << " " << t << "\n\n";
        }

        // reverse
        s = os;
        t = ot;
        for(int d = 9; d >= 0; d--){
            string ns = "", nt = "";

            // cout << d << endl;

            int dt = 0, ds = 0;
            for(int i = 0; i < s.size(); i++){

                if(s[i] == d + '0') ds++;
                else ns += s[i];

                if(t[i] == d + '0') dt++;
                else nt += t[i];

                // cout << ds << ' ' << dt << endl;

                if(ds < dt) return false;
            }

            s = ns;
            t = nt;
            // cout << s << " " << t << "\n\n";
        }

        return true;
    }
};