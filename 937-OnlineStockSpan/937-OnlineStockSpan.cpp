// Last updated: 6/25/2026, 11:20:04 PM
class StockSpanner {
public:
    stack<pair<int, int>> st;
    int next(int price) {
        int f = 1;
        while (!st.empty() && price >= st.top().first) {
            f += st.top().second;
            st.pop();
        }
        st.push({price, f});
        return f;
    }
};