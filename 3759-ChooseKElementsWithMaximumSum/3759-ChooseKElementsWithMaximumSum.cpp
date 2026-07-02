// Last updated: 7/2/2026, 11:35:14 PM
class Solution {
public:
    using ll = long long;

    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<array<int,2>, vector<array<int,2>>, greater<>> pq; // {nums1, index}

        int n = nums1.size();

        for(int i = 0; i < n; i++)
            pq.push({nums1[i], i});

        priority_queue<int, vector<int>, greater<int>> q;

        vector<ll> ans(n);
        ll sum = 0;

        while(!pq.empty()){
            vector<int> same;

            int x = pq.top()[0];

            // First assign answers for all equal nums1
            while(!pq.empty() && pq.top()[0] == x){
                auto [_, i] = pq.top(); pq.pop();
                ans[i] = sum;
                same.push_back(i);
            }

            // Then insert their nums2 values
            for(int i : same){
                sum += nums2[i];
                q.push(nums2[i]);

                if(q.size() > k){
                    sum -= q.top();
                    q.pop();
                }
            }
        }

        return ans;
    }
};