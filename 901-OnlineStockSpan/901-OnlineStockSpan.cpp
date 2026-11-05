// Last updated: 11/6/2026, 5:11:14 AM
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