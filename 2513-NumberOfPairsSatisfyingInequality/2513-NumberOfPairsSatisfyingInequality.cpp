// Last updated: 6/25/2026, 11:11:37 PM
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template<typename T>
using SET = tree<
    pair<T,int>,
    null_type,
    less<pair<T,int>>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {

        int n = nums1.size();

        SET<long long> s;

        long long ans = 0;

        for(int i = 0; i < n; i++){

            long long x = 1LL * nums1[i] - nums2[i];

            ans += s.order_of_key({x + diff, n});

            s.insert({x, i});
        }

        return ans;
    }
};