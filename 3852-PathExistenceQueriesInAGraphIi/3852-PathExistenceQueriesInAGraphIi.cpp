// Last updated: 7/18/2026, 12:22:19 AM
class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        priority_queue<array<int,2>> pq;
        int LOG = max(1, (int)ceil(log2(n)));

        for (int i = 0; i < n; i++) pq.push({nums[i], i});

        vector<int> tf(n);
        int j = n;
        while (!pq.empty()) {
            auto [x, i] = pq.top(); pq.pop();
            tf[i] = --j;
        }

        ranges::sort(nums);

        vector<vector<int>> reach(n, vector<int>(LOG + 1, -1));

        int r = 0;
        for (int i = 0; i < n; i++) {
            while (r < n && nums[r] - nums[i] <= maxDiff) r++;
            int furthest = r - 1;
            reach[i][0] = (furthest > i) ? furthest : -1;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= LOG; k++) {
                if (reach[i][k - 1] != -1) reach[i][k] = reach[reach[i][k - 1]][k - 1];
            }
        }

        vector<int> ans;
        for (auto &q : queries) {
            int u = min(tf[q[0]], tf[q[1]]);
            int v = max(tf[q[0]], tf[q[1]]);

            int steps = 0;
            for (int k = LOG; k >= 0; k--) {
                if (reach[u][k] != -1 && reach[u][k] < v) {
                    steps += (1 << k);
                    u = reach[u][k];
                }
            }

            if (u == v) ans.push_back(steps);
            else if (reach[u][0] >= v) ans.push_back(steps + 1);
            else ans.push_back(-1);
        }

        return ans;
    }
};