// Last updated: 6/24/2026, 3:26:50 AM
class Solution {
public:
    int maxFixedPoints(vector<int>& A) {
        
        vector<pair<int,int>> b;

        for(int i = 0; i < A.size(); i++){

            if(i >= A[i])
                b.push_back({i - A[i], A[i]});
        }

        sort(b.begin(), b.end());

        vector<int> lis;

        for(auto &[x,y] : b){

            auto it = ranges::lower_bound(lis, y);

            if(it == lis.end()) lis.push_back(y);

            else *it = y;
        }

        return lis.size();
    }
};