// Last updated: 8/20/2026, 9:05:16 PM
class Solution {
public:
    int size;
    int next(int i, vector<int> &v){
        v[i] %= size;
        return ((i + v[i]) % size + size) % size; 
    }
    bool circularArrayLoop(vector<int>& v) {
        size = v.size();
        for(int i = 0; i < size; i++){
            int slow = i, fast = next(i, v);
            while(slow != fast){
                slow = next(slow, v);
                fast = next(fast, v);
                if(v[slow] * v[i] < 0 || v[fast] * v[i] < 0) break;
                fast = next(fast, v);
                if(v[fast] * v[i] < 0) break;
            }
            if(slow == fast and v[slow] * v[i] > 0) return true;
        }
        return false;
    }
};