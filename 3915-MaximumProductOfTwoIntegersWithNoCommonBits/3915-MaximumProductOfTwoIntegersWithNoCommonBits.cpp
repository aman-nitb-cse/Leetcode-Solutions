// Last updated: 6/24/2026, 3:29:37 AM
class Tries {
public:
	Tries* bit[2] = {NULL};
    int val = -1;
	
	void insert(int x, int i = 20){
		if(i < 0) {
            val = x;
            return;
        }
		
		int b = (x >> i) & 1;
		
		if(bit[b] == NULL) bit[b] = new Tries();
		
		bit[b]->insert(x, i - 1);
	}

    int get(int x, int i = 20) {
        if(i < 0) return val;
        int b = (x >> i) & 1;

        if(bit[1] && !b) {
            int res = bit[1]->get(x, i - 1);
            if(res != -1) return res;
        }
        
        return bit[0] ? bit[0]->get(x, i - 1) : -1;
    }
};

class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        auto node = new Tries();

        for(int &i : nums) node->insert(i);

        long long ans = 0;
        for(int &i : nums){
            ans = max(ans, 1LL * i * node->get(i));
        }

        return ans;
    }
};