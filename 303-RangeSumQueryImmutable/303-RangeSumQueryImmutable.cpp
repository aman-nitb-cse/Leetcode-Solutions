// Last updated: 8/20/2026, 9:09:18 PM
class NumArray {
public:
    vector<int> v;
    NumArray(vector<int>& nums) : v(nums) {
        for(int i = 1; i < v.size(); i++){
            v[i] += v[i - 1];
        }
    }
    
    int sumRange(int left, int right) {
        return left ? v[right] - v[left - 1] : v[right];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */