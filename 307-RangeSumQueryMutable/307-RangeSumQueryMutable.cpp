// Last updated: 8/20/2026, 9:09:10 PM
struct BIT {
    using ll = int;
    
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

class NumArray {
public:
    vector<int> nums;
    BIT bit;

    NumArray(vector<int>& nums) : nums(nums), bit(nums) {}
    
    void update(int index, int val) {
        int diff = val - nums[index];
        nums[index] = val;

        bit.update(index + 1, diff);
    }
    
    int sumRange(int left, int right) {
        return bit.query(left + 1, right + 1);
    }
};