// Last updated: 8/20/2026, 9:12:47 PM
class MinStack {
public:
    stack<int> st, minStack;
    void push(int val) {
        st.push(val);
        if (minStack.empty() || val <= minStack.top()) minStack.push(val);
    }
    void pop() {
        if (st.top() == minStack.top()) minStack.pop();
        st.pop();
    }
    int top() { 
        return st.top(); 
    }
    int getMin() { 
        return minStack.top(); 
    }
};