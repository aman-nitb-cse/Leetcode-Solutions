// Last updated: 6/25/2026, 11:16:35 PM
class Solution {
public:
    int maxEvents(vector<vector<int>>& e) {
        sort(e.begin(), e.end());
        priority_queue<int, vector<int>, greater<int>> pq;

        int curr = e[0][0];
        int i = 0;
        int count = 0;
        while(i < e.size() || !pq.empty()){
            if(pq.empty())
                curr = e[i][0];

            while(i < e.size() && curr >= e[i][0]) pq.push(e[i++][1]);
            if(!pq.empty()){
                count++;
                pq.pop();
            }

            curr++;
            while(!pq.empty() && curr > pq.top()) pq.pop();
        }
        return count;
    }
};