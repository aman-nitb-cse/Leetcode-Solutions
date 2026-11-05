// Last updated: 11/6/2026, 5:00:37 AM
class Solution {
public:
    int furthestBuilding(vector<int>& h, int b, int l) {

        priority_queue<int> pq;

        for(int i = 0; i + 1 < h.size(); i++){

            int diff = h[i + 1] - h[i];

            if(diff <= 0) continue;

            if(l){
                pq.push(-diff);
                l--;
                diff = 0;
            }
            else if(!pq.empty() && diff > -pq.top()){

                int t = -pq.top();

                pq.pop();

                pq.push(-diff);

                diff = t;
            }

            if(b >= diff) b -= diff;
            else return i;
        }

        return h.size() - 1;
    }
};