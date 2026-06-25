// Last updated: 6/25/2026, 11:11:17 PM
class Solution {
public:
    vector<int> nums;
    vector<int> bs(int k){
        int s = 0;
        int e = nums.size() - 1;
        while(s <= e){
            int mid = s + (e - s) / 2;
            if(nums[mid] == k) return {k, k};
            if(nums[mid] < k) s = mid + 1;
            else e = mid - 1;
        }
        if(e == -1) return {-1, nums[0]};
        if(s == nums.size()) return {nums.back(), -1};
        return {nums[e], nums[s]};
    }

    void to_vector(TreeNode* root){
        if(!root) return;
        to_vector(root->left);
        nums.push_back(root->val);
        to_vector(root->right);
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& v) {
        to_vector(root);
        vector<vector<int>> ans;
        for(int &i : v){
            ans.push_back(bs(i));
        }
        return ans;
    }
};