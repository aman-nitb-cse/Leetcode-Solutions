// Last updated: 6/24/2026, 3:32:18 AM
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& health, string dir) {
        priority_queue<pair<int,int>> pq;

        for(int &p : pos){
            pq.push({p, pq.size()});
        }
        stack<int> st;

        while(!pq.empty()){
            int left = pq.top().second; pq.pop();
            if(st.empty()){
                st.push(left);
                continue;
            }

            int right = st.top(); st.pop();
            // collision
            if(dir[left] > dir[right]){
                // pq wins
                if(health[left] > health[right]){
                    health[left]--;
                    pq.push({pos[left], left});
                }
                // stack wins
                else if(health[left] < health[right]) {
                    health[right]--;
                    st.push(right);
                }
            }
            // no collision
            else {
                st.push(right);
                st.push(left);
            }
        }

        pos.clear();
        while(!st.empty()){
            int i = st.top(); st.pop();
            pq.push({-i, 0});
        }

        while(!pq.empty()){
            int i = pq.top().first; pq.pop();
            pos.push_back(health[-i]);
        }
        return pos;
    }
};