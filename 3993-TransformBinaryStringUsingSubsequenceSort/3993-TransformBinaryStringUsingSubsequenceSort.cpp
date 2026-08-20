// Last updated: 8/20/2026, 8:35:47 PM
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n = s.length();
        int total_ones = 0;
        vector<int> s_prefix(n, 0);
        
        // Precompute the prefix sum of '1's for string s
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                total_ones++;
            }
            s_prefix[i] = total_ones;
        }
        
        vector<bool> ans;
        ans.reserve(strs.size());
        
        for (const string& t : strs) {
            int t1 = 0;
            int t0 = 0;
            int total_qs = 0;
            
            // Count characters in the current target string
            for (char c : t) {
                if (c == '1') t1++;
                else if (c == '0') t0++;
                else total_qs++;
            }
            
            // Fast fail if there are already too many 1s or 0s
            if (t1 > total_ones || t0 > n - total_ones) {
                ans.push_back(false);
                continue;
            }
            
            int needed_ones = total_ones - t1;
            int qs_to_zero = total_qs - needed_ones; // Number of '?'s to replace with '0' from left to right
            
            bool is_valid = true;
            int t_ones = 0;
            
            // Traverse to check the prefix rule without building a new string
            for (int i = 0; i < n; ++i) {
                if (t[i] == '1') {
                    t_ones++;
                } else if (t[i] == '?') {
                    if (qs_to_zero > 0) {
                        qs_to_zero--; // Treat this '?' as '0'
                    } else {
                        t_ones++;     // Treat this '?' as '1'
                    }
                }
                
                // If prefix sum of 1s in t exceeds prefix sum of 1s in s, it's invalid
                if (t_ones > s_prefix[i]) {
                    is_valid = false;
                    break;
                }
            }
            
            ans.push_back(is_valid);
        }
        
        return ans;
    }
};