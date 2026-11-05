// Last updated: 11/6/2026, 5:08:16 AM
class Solution {
public:
    int lastStoneWeight(vector<int>& nums) {
        priority_queue<int> pq(nums.begin(), nums.end());

        while(pq.size() > 1){
            int y = pq.top(); pq.pop();
            int x = pq.top(); pq.pop();

            pq.push(y - x);
        }
        return pq.top();
    }
};