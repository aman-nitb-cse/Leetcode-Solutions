// Last updated: 6/24/2026, 3:32:29 AM
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
    long long countOperationsToEmptyArray(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();

        priority_queue<array<int,2>> pq;
        for(int i = 0; i < n; i++) pq.push({ - nums[i], i});

        vector<int> alive(n, 1);


        BIT bit(alive);
        int i = 0;
        while(!pq.empty()){
            int j = pq.top()[1]; pq.pop();

            if(i <= j) ans += bit.query(i, j);
            else ans += bit.query(i, n - 1) + bit.query(0, j);

            bit.update(j, -1);
            i = j;
        }

        return ans;
    }
};
