// Last updated: 6/24/2026, 3:26:40 AM
class Solution {
public:
    long long minEnergy(int n, int b, vector<vector<int>>& I) {
        ranges::sort(I);

        long long prev = 0, time = 0;
        for(auto &v : I){
            long long s = v[0], e = v[1];
            if(e >= prev) {
                time += e + 1 - max(prev, s);
                prev = e + 1;
            }

        }

        cout << time << endl;

        return time * ((b + 2) / 3);
    }
};