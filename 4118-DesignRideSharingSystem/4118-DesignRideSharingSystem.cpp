// Last updated: 6/24/2026, 3:28:46 AM
class RideSharingSystem {
public:
    queue<int> R;
    queue<int> D;
    unordered_set<int> st;
    void addRider(int riderId) {
        R.push(riderId);
        if(st.find(riderId) != st.end()) st.erase(riderId);
    }
    
    void addDriver(int driverId) {
        D.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        if(R.empty() || D.empty()) return {-1, -1};
        if(st.find(R.front()) != st.end()){
            R.pop();
            return matchDriverWithRider();
        }
        vector<int> ans = {D.front(), R.front()};
        D.pop();
        R.pop();
        return ans;
    }
    
    void cancelRider(int riderId) {
        st.insert(riderId);
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */