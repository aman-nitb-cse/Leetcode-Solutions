// Last updated: 8/20/2026, 9:10:42 PM
class MyQueue {
    stack <int> main, temp;
public:
    void push(int x) {
        main.push(x);
    }
    
    int pop() {
        if(main.empty()) return -1;
        int x;
        while(!main.empty()){
            x = main.top();
            temp.push(x);
            main.pop();
        }
        temp.pop();
        while(!temp.empty()){
            main.push(temp.top());
            temp.pop();
        }
        return x;
    }
    
    int peek() {
        if(main.empty()) return -1;
        int x;
        while(!main.empty()){
            x = main.top();
            temp.push(x);
            main.pop();
        }
        
        while(!temp.empty()){
            main.push(temp.top());
            temp.pop();
        }
        return x;
    }
    
    bool empty() {
        return main.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */