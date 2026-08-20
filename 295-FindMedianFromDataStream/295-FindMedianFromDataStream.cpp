// Last updated: 8/20/2026, 9:09:28 PM
class MedianFinder {
public:
    priority_queue<int> left; // max heap
    priority_queue<int, vector<int>, greater<int>> right; // min heap
    void addNum(int n) {
        if(left.empty() || n <= left.top()) left.push(n); 
        else right.push(n);

        while(left.size() < right.size()) {
            left.push(right.top());
            right.pop();
        }

        while(left.size() > right.size() + 1){
            right.push(left.top());
            left.pop();
        }
    }
    
    double findMedian() {
        if(left.size() == right.size()) return (left.top() + right.top()) / 2.0;
        return left.top();
    }
};