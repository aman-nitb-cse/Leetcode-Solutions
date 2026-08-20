// Last updated: 8/20/2026, 9:02:15 PM
class Solution {
public:
    int maximumProduct(vector<int>& A) {
        ranges::sort(A);
        int n = A.size();
        
        return max(
            A.back() * A[n - 2] * A[n - 3],
            A.back() * A.front() * A[1]
        );
    }
};