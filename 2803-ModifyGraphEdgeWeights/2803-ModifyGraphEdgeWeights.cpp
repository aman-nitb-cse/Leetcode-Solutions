// Last updated: 7/18/2026, 12:24:43 AM
class Solution {
public:
    const int INF = 2e9;
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int src, int dest, int target) {
        // Step 1: Compute the initial shortest distance from src to dest
        long long currentShortestDistance = runDijkstra(edges, n, src, dest);

        // If the current shortest distance is less than the target, return an
        // empty result
        if (currentShortestDistance < target) return {};

        if (currentShortestDistance == target) {

            // Make all -1 edges unusable
            for (auto &edge : edges) {
                if (edge[2] == -1) edge[2] = INF;
            }

            return edges;
        }

        // currentShortestDistance > target

        for (auto &edge : edges) {

            if (edge[2] != -1) continue;

            edge[2] = 1;

            long long newDistance = runDijkstra(edges, n, src, dest);

            if (newDistance <= target) {

                edge[2] += target - newDistance;

                for (auto &e : edges) {
                    if (e[2] == -1)
                        e[2] = INF;
                }

                return edges;
            }
        }

        return {};
    }

    // Dijkstra's algorithm to find the shortest path distance [ignore -1 edges]
    long long runDijkstra(const vector<vector<int>>& edges, int n, int src, int dest) {
        vector<vector<pair<int, int>>> graph(n);

        for (const auto &edge : edges) {
            if (edge[2] == -1) continue;

            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        vector<long long> minDistance(n, INF);
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        minDistance[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d != minDistance[u]) continue;
            if (u == dest) break;

            for (auto &[v, w] : graph[u]) {
                if (minDistance[v] > d + w) {
                    minDistance[v] = d + w;
                    pq.push({minDistance[v], v});
                }
            }
        }

        return minDistance[dest];
    }
};