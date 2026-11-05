// Last updated: 11/6/2026, 4:58:36 AM
class SeatManager {
public:
    set<int> st;

    SeatManager(int n) {
        for(int i = 1; i <= n; i++)
            st.insert(i);
    }

    int reserve() {
        int x = *st.begin();
        st.erase(st.begin());
        return x;
    }

    void unreserve(int seatNumber) {
        st.insert(seatNumber);
    }
};