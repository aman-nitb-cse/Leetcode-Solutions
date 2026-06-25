// Last updated: 6/25/2026, 11:14:19 PM
class FindSumPairs {
public:
    vector <int>& nums1, nums2;
    unordered_map <int, int> hash;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) : nums1(nums1), nums2(nums2) {
        for(int &i : nums2) hash[i]++;
    }
    
    void add(int index, int val) {
        hash[nums2[index]]--;
        nums2[index] += val;
        hash[nums2[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for(int &i : nums1){
            int target = tot - i;
            if(hash.find(target) != hash.end()){
                ans += hash[target];
            }
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */