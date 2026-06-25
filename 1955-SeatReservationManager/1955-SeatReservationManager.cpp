// Last updated: 6/25/2026, 11:14:39 PM
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