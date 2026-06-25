// Last updated: 6/25/2026, 11:15:26 PM
struct BIT {
    using ll = long long;
    
    int n;
    vector<ll> bit;
    
    BIT(int n) : n(n) {
        bit.assign(n + 1, 0);
    }
    
    BIT(vector<int>& nums) : BIT(nums.size()) {
        
        for(int i = 1; i <= n; i++) {
            
            bit[i] += nums[i - 1];
            
            int par = i + (i & -i);
            
            if(par <= n) bit[par] += bit[i];
        }
    }
    
    void update(int i, ll diff) {
        
        while(i <= n) {
            
            bit[i] += diff;
            
            i += i & -i;
        }
    }
    
    ll query(int i) {
        
        ll ans = 0;
        
        while(i) {
            
            ans += bit[i];
            
            i -= i & -i;
        }
        
        return ans;
    }
    
    ll query(int l, int r) {
        return query(r) - query(l - 1);
    }
};


class Solution {
public:
    int createSortedArray(vector<int>& nums) {
        int sz = 100001;
        BIT bit(sz);

        int ans = 0;
        const int mod = 1e9 + 7;

        for(int &i : nums){
            ans += min(bit.query(i + 1, sz - 1), bit.query(1, i - 1));
            ans %= mod;

            bit.update(i, 1);
        }

        return ans;
    }
};