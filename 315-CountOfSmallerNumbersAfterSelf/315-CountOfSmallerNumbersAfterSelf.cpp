// Last updated: 8/20/2026, 9:09:01 PM
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using SET = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {

        int n = nums.size();

        SET<pair<int,int>> os;

        vector<int> ans(n);

        for(int i = n - 1; i >= 0; i--){

            ans[i] = os.order_of_key({nums[i], -1});

            os.insert({nums[i], i});
        }

        return ans;
    }
};