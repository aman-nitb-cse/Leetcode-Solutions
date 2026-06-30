// Last updated: 6/30/2026, 2:14:52 PM
class Solution {
public:
    int minGroups(vector<vector<int>>& I) {
        ranges::sort(I);

        priority_queue<int> pq;

        for(auto &v : I){
            int s = v[0], e = v[1];

            if(!pq.empty() && -pq.top() < s)
                pq.pop();

            pq.push(-e);
        }

        return pq.size();
    }
};