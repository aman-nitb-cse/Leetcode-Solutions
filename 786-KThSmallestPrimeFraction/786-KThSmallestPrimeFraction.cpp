// Last updated: 11/6/2026, 5:13:15 AM
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double, array<int,2>>> pq;

        for(int i = 0; i < arr.size(); i++){
            for(int j = i + 1; j < arr.size(); j++){
                pq.push({-1.0 * arr[i] / arr[j], {arr[i], arr[j]}});
            }
        }

        while(--k) pq.pop();

        auto [_, p] = pq.top();

        return {p[0], p[1]};
    }
};