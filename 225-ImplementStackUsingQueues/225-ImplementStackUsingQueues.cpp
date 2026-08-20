// Last updated: 8/20/2026, 9:11:01 PM
class MyStack {
    queue <int> main, temp;
public:
    void push(int x) {
        main.push(x);
    }
    
    int pop() {
        if(main.empty()) return -1; 
        int x;
        while(!main.empty()){
            x = main.front();
            temp.push(x);
            main.pop();
        }

        while(!temp.empty()){
            if(x != temp.front()) main.push(temp.front());
            temp.pop();
        }
    
        return x;
    }
    
    int top() {
        if(main.empty()) return -1; 
        int x;
        while(!main.empty()){
            x = main.front();
            temp.push(x);
            main.pop();
        }

        while(!temp.empty()){
            main.push(temp.front());
            temp.pop();
        }
    
        return x;
    }
    
    bool empty() {
        return main.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */