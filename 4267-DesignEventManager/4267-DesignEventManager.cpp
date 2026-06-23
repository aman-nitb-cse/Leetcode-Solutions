// Last updated: 6/24/2026, 3:27:21 AM
class EventManager {
public:
    unordered_map<int,int> ev;
    priority_queue<pair<int,int>> pq;

    EventManager(vector<vector<int>>& events) {
        for(auto &v : events){
            ev[-v[0]] = v[1];
            pq.push({v[1], -v[0]});
        }
    }
    
    void updatePriority(int eid, int np) {
        ev[-eid] = np;
        pq.push({np, -eid});
    }
    
    int pollHighest() {
        while(!pq.empty()){
            auto [p, eid] = pq.top(); pq.pop();
            if(ev[eid] == p){
                ev.erase(eid);
                return -eid;
            }
        }
        return -1;
    }
};