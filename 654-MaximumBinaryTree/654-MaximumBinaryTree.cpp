// Last updated: 8/20/2026, 9:01:27 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* f(vector<int>& nums, int s, int e){
        if(s > e) return NULL;
        int i = max_element(nums.begin() + s, nums.begin() + e + 1) - nums.begin();
        return new TreeNode(nums[i], f(nums, s, i - 1), f(nums, i + 1, e));
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return f(nums, 0, nums.size() - 1);
    }
};