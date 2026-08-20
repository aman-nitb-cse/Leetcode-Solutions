// Last updated: 8/20/2026, 9:04:25 PM
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
        
        i++;
        
        while(i <= n) {
            
            bit[i] += diff;
            
            i += i & -i;
        }
    }
    
    ll query(int i) {
        i++;
        
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
    int reversePairs(vector<int>& nums) {

        vector<long long> vals;

        for(int x : nums){
            vals.push_back(x);
            vals.push_back(2LL * x);
        }

        ranges::sort(vals);

        vals.erase(
            unique(vals.begin(), vals.end()),
            vals.end()
        );

        unordered_map<long long,int> index;

        for(int i = 0; i < vals.size(); i++)
            index[vals[i]] = i;

        BIT bit(vals.size());

        long long ans = 0;

        for(int i = 0; i < nums.size(); i++){

            ans += i - bit.query(index[2LL * nums[i]]);

            bit.update(index[nums[i]], 1);
        }

        return ans;
    }
};