// Last updated: 6/25/2026, 11:20:37 PM
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        int n = hand.size();
        if(n % k) return false;

        multiset<int> st(hand.begin(), hand.end());

        while(!st.empty()){
            int mini = *st.begin(); st.erase(st.begin());
            for(int i = mini + 1; i < mini + k; i++){
                auto it = st.find(i);
                if(it != st.end()) st.erase(it);
                else return false;
            }
        }
        return true;
    }
};