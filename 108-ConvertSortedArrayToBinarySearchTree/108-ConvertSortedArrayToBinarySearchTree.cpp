// Last updated: 8/20/2026, 9:15:01 PM
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
    TreeNode* sortedArrayToBST(vector<int>& nums, int s = 0, int e = -2) {
        if(e == -2) e = nums.size() - 1;
        if(s > e) return nullptr;
        int mid = (s + e) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(nums, s, mid - 1);
        root->right = sortedArrayToBST(nums, mid + 1, e);
        return root;
    }
};