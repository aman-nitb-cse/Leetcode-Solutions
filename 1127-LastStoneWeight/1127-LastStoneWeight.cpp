// Last updated: 6/25/2026, 11:18:32 PM
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