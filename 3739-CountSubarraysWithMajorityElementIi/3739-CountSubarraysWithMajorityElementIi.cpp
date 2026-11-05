// Last updated: 11/6/2026, 4:39:28 AM
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using SET = tree<
    T, // key
    null_type, // value
    greater<T>, // comparator
    rb_tree_tag,
    tree_order_statistics_node_update
>;

// s.order_of_key(x) : number of element before x
// *s.find_by_order(i) : value at index i


class Solution {
public:
    
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        
        SET<pair<int,int>> st;

        int n = nums.size();

        int f = 0;
        for(int i = 0; i < n; i++){
            f += (nums[i] == target);
            st.insert({2 * f - i - 1, i});
        }

        int diff = 0;

        long long ans = 0;

        for(int i = 0; i < n; i++){

            ans += st.order_of_key({diff, n});

            if(nums[i] == target) diff++;
            else diff--;

            st.erase({diff, i});
        }

        return ans;
    }
};